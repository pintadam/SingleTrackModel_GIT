#ifndef ayc_yref_h_included                                                    /* --> .!003MS090199. */
#define ayc_yref_h_included

#include "ayc_init.h"
#include "hal_base_type_if.he"
#include "math_lib.he"
#include "ayc_stm_para.h"

#define __SFL_INLINE__        Global_inline



/******************************************************************************
 * 'P A R A M E T E R - D E F I N E S'                                        *
 ******************************************************************************/

#define Loop_time_float                   (10000.0)
#define Esm_c1_alpha_max                  1840
#define Esm_c2_alpha_max                  17854
#define Esm_filter_vref_max               10000
#define Loop_time                         (100*(signed_int16_t)(Loop_time_float/100.0))
#define Loop_time_ms                      ((unsigned_int16_t)(Loop_time_float/1000.0))
#define Loop_time_sec                     (float32) ((float32)Loop_time*1E-6)
#define Get_sas_initialized()             1
#define Get_fric_reset_of_ayc_control()   1
#define Get_ayc_status_first_run()        1
#define Get_counter_steer()               1
/*
@details FILTER PT1 MACROS FOR
             Frequency Domain        : Filter Coefficient represented as Sampling time and Cut off frequency
             Time Domain             : Filter Coefficient represented as Sampling time and Time Constant
             Special Cases           : Filter Coefficient is a variable or is from PDB
@return
@param unfiltered_val
*/
#define Unfiltered_value(unfiltered_val )       (unfiltered_val)

/*
@details FILTER PT1 MACROS FOR
             Frequency Domain        : Filter Coefficient represented as Sampling time and Cut off frequency
             Time Domain             : Filter Coefficient represented as Sampling time and Time Constant
             Special Cases           : Filter Coefficient is a variable or is from PDB
@return
@param filtered_old_val
*/
#define Filtered_old_value(filtered_old_val)    (filtered_old_val)

/*
@details FILTER PT1 MACROS FOR
             Frequency Domain        : Filter Coefficient represented as Sampling time and Cut off frequency
             Time Domain             : Filter Coefficient represented as Sampling time and Time Constant
             Special Cases           : Filter Coefficient is a variable or is from PDB
@return
@param sampling_time_ms
*/
#define Sampling_time_ms(sampling_time_ms)      ((float32)(sampling_time_ms))

/*
@details
@return
@param cut_off_freq_hz
*/
#define Cut_off_freq_hz(cut_off_freq_hz)            ((float32)(cut_off_freq_hz))

/*
@details FILTER PT1 MACROS FOR
             Frequency Domain        : Filter Coefficient represented as Sampling time and Cut off frequency
             Time Domain             : Filter Coefficient represented as Sampling time and Time Constant
             Special Cases           : Filter Coefficient is a variable or is from PDB
@return
@param sc_fac
*/
#define Scaling_factor(sc_fac)                  ((unsigned_int16_t)(sc_fac))

/*
@details MACROS FOR ROUNDING OFF RESULTS AFTER FLOATING POINT CALCULATIONS
@return
@param i
*/
#define Unsigned_int16_round(i)        ((unsigned_int16_t)((i)+0.5))

/*
@details
@return
@param cut_off_freq_hz
*/
#define Cut_off_freq_hz(cut_off_freq_hz)            ((float32)(cut_off_freq_hz))


/*
@details
@return
@param cut_off_freq_hz
@param sampling_time_ms
*/
#define Filter_coefficient_hz(cut_off_freq_hz,sampling_time_ms) ((float32)( 1.0 / ( 1.0 + (6.2832 * (cut_off_freq_hz) * ((sampling_time_ms) / 1000.0))) ))

#define Filter_pt1_hz(unfilt_val,filt_old_val,sampling_time_ms,cut_off_freq_hz,sc_fac) ( \
  (unfilt_val) + \
   ((Unsigned_int16_round(Filter_coefficient_hz((cut_off_freq_hz),(sampling_time_ms)) * (float64)(sc_fac)) \
     * (signed_int32_t)( (filt_old_val) - (unfilt_val) ) \
    ) / (sc_fac) ) \
)

#define Set_fric_reset_of_ayc_control(x) (AYC_FRICTION_BITS.RESET_OF_AYC_CONTROL = (x))
/******************************************************************************
 * 'C O N S T - D E F I N I T I O N S'                                        *
 ******************************************************************************/

/******************************************************************************
 * 'T Y P E - D E C L A R A T I O N S'                                        *
 ******************************************************************************/

typedef signed short int        signed_int16_t;
typedef signed int              signed_int32_t;
typedef unsigned char           unsigned_char_t;


typedef struct 
{
   unsigned int            MODEL_RESET                 : 1;   /*@ NAME:MODEL_RESET  REM: @*/
   unsigned int            MODEL_RESET_BACK            : 1;   /*@ NAME:MOD_RES_BACK REM:Flag to allow back-reset if no control @*/
   unsigned int            BACKSTEER_FOR_MODEL         : 1;   /*@ NAME:BACKSTEER_M  REM:quick Steering back reaction @*/
   unsigned int            COUNTER_RESET_FOR_ADAPT_C_R : 1;   /*@ NAME:CNT_RES_C_R  REM: @*/
   unsigned int            ADAPTION_OF_C_R_POSSIBLE    : 1;   /*@ NAME:ADAPT_CR_POS REM: @*/
   unsigned int            BKST_FOR_MODEL_FILTER       : 1;   /*@ NAME:BKST_MOD_FIL REM:filtered Steering back reaction @*/       /* .#a001KO111202. */
   unsigned int            BETA_RESET_PROHIBITED       : 1;   /*@ NAME:RESET_PROHIB REM:Flag to prohibit reset of beta in instationary situations @*/
   unsigned int            BIT7                        : 1;
} ayc_stm_bits_t;

typedef struct
{
   unsigned int            RESET_OF_AYC_CONTROL : 1;             /*@ NAME:RES_AYC_CTRL REM:Reset single track model after determination of the friction coefficient @*/
   unsigned int            STATE_TRIGGER        : 2;             /*@ NAME:STATETRIGGER REM:Current state of the friction coefficient estimation @*/
   unsigned int            RUNNING              : 1;             /*@ NAME:RUNNING      REM:Friction coefficient estimation is running @*/
   unsigned int            FRIC_DEC_CNT         : 2;             /*@ NAME:FRIC_DEC_CNT REM:counter for resetting of my correction @*/
   unsigned int            BIT6                 : 1;             /*@ NAME:             REM:                                       @*/
   unsigned int            MY_CORRECTION        : 1;             /*@ NAME:MY_CORR      REM:my correction activ or not @*/
} ayc_friction_bits_t;

signed_int16_t             AYC_REFERENCE_VELOCITY;
signed_int16_t             AYC_CONTROL_DEVIATION;

/******************************************************************************
 * 'B I T - S T R U C T U R E S'                                              *
 ******************************************************************************/

 extern ayc_stm_bits_t            AYC_STM_BITS;                   /*@ NAME:STM_BIT      REM:AYC single track model bits @*/
 extern ayc_friction_bits_t       AYC_FRICTION_BITS;

/******************************************************************************
 * 'C H A R A C T E R - V A R I A B L E S'                                    *
 ******************************************************************************/

 extern unsigned_char_t                        ESM_DEBOUNCE_TIMER;              /*@ LSB:1        UNIT:loop   NAME:ESM_DEBOUNCE REM:reference yawrate debounce timer, ref_yr may swing after initialization @*/

/******************************************************************************
 * 'I N T E G E R - V A R I A B L E S'                                        *
 ******************************************************************************/

 extern unsigned_char_t  AYC_ESTIMATED_MY;

 extern signed_int16_t                         AYC_SLIP_ANGLE_REF;              /*@ LSB:1.526e-3 UNIT:deg     NAME:SLP_ANG_REF  REM:side slip of single track model @*/
 extern signed_int16_t                         AYC_YAW_RATE_MODEL;              /*@ LSB:2.865e-3 UNIT:deg/s   NAME:YAWRATE_MODL REM:yawrate of single track model @*/
 extern signed_int16_t                         AYC_SLIP_ANGLE_RATE_REF;         /*@ LSB:0.18336  UNIT:deg/s   NAME:SLP_ANG_RATE REM:side slip acceleration of single track model kept in mind for Runge-Kutta Integration @*/

 extern signed_int16_t                         AYC_SLIP_ANGLE_BACK;             /*@ LSB:1.526e-3 UNIT:deg     NAME:SLP_ANG_BACK REM:saved side slip of single track model for model-reset @*/
 extern signed_int16_t                         AYC_YAW_RATE_BACK;               /*@ LSB:2.865e-3 UNIT:deg/s   NAME:YAWRATE_BACK REM:saved yawrate of single track model for model-reset @*/

 extern signed_int16_t                         AYC_FF_LAT_OLD;                  /*@ LSB:2        UNIT:N       NAME:FF_LAT_OLD   REM:stored value of lateral force at the front axle @*/

 extern signed_int16_t                         IALPHA_F_BACK;                   /*@ LSB:7.63e-4  UNIT:deg     NAME:IALPHA_F_BCK REM: @*/

 extern signed_int16_t                         Esm_c1_alphaf;
 extern signed_int16_t                         AYC_DRV_REQ_STEER_ANGLE;

 extern signed_int16_t                         STM_LAT_FORCE_REAR;

 extern signed_int16_t                         AYC_DT_CONTROL_DEVIATION;     /*@ LSB:2.865e-3 UNIT:deg/ss  NAME:DT_CTRL_DEV  REM:derivation of ayc control deviation @*/ /* .#003gae120399. */
 extern signed_int16_t                         AYC_YAW_ACC_REF;              /*@ LSB:0.4092   UNIT:deg/s/s NAME:YAW_ACC_REF  REM:yaw acceleration of single track model @*/
 extern signed_int16_t                         AYC_SLIP_ANGLE_RATE_RA;

 extern signed_int16_t                         AYC_YAW_RATE_REF;

 extern signed_int16_t                         AYC_REF_YAW_RATE_FROM_SA;               /*!< @ASAP_NAME   REFYRSA @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   reference yaw rate derived from steer angle */
 extern signed_int16_t                         AYC_REF_YAW_RATE_FROM_SA_FIL;           /*!< @ASAP_NAME   REFYRSAF @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   filtered reference yaw rate derived from steer angle */
 extern signed_int16_t                         UNCALIBRATED_YAW_RATE;                  /*!< @ASAP_NAME   RAWYR @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   uncalibrated and not filtered yaw rate */
 extern signed_int16_t                         UNCALIBRATED_YAW_RATE_FIL;              /*!< @ASAP_NAME   RAWYRFL @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   uncalibrated but filtered yaw rate */
 extern signed_int16_t                         YAW_RATE;                               /*!< @ASAP_NAME   YR @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   calibrated but not filtered yaw rate */
 extern signed_int16_t                         UNCALIBRATED_YAW_RATE_LBO;

 extern signed_int16_t                AYC_DBETAP_OLD;                 /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPRA_OLD  REM:BETAP rear axle of last loop @*/
 extern signed_int16_t                AYC_CONTROL_DEVIATION_OLD;      /*@ LSB:2.865e-3 UNIT:deg/s NAME:CTRL_DEV_OLD REM:AYC control deviation of last loop @*/
 extern signed_int16_t                AYC_REQUESTED_YAW_TORQUE_OLD;   /*@ LSB:0.1      UNIT:bar     NAME:ZUSMOM_OLD       REM:AYC requested yaw torque last loop@*/

 extern unsigned_int16_t              AYC_SLIP_ANGLE_RATE_RA_ABS;     /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPRA_ABS  REM:BETAP rear axle absolute value @*/
 extern signed_int16_t                AYC_DPSIP_TH_IN_CTRL;           /*@ LSB:2.865e-3 UNIT:deg/s NAME:DPSIPIN      REM:Yawrate deviation threshold for entering control @*/
 extern signed_int16_t                AYC_BETAP_TH_IN_CTRL;           /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPIN      REM:Slip angle rate threshold for entering control @*/
 extern signed_int16_t                AYC_DPSIP_TH_OUT_CTRL;          /*@ LSB:2.865e-3 UNIT:deg/s NAME:DPSIPOUT     REM:Yawrate deviation threshold for leaving control @*/
 extern signed_int16_t                AYC_BETAP_TH_OUT_CTRL;          /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPOUT     REM:Slip angle rate threshold for leaving control @*/
 extern signed_int16_t                AYC_K_BETAP;                    /*@                         NAME:KBETAP       REM:Gain factor for slip angle rate control @*/
 extern signed_int16_t                AYC_K_DPSIP;                    /*@                         NAME:KDPSIP       REM:Gain factor for dpsip-torque @*/
 extern signed_int16_t                AYC_K_DPSIP_DT;                 /*@                         NAME:KDPSIP_DT    REM:Gain factor for DT-part dpsip-torque @*/
 extern signed_int16_t                AYC_STORED_LGA;                 /*@ LSB:0.014    UNIT:deg   NAME:STORED_LGA   REM:keep old value of lateral gradient angle @*/
 extern signed_int16_t                AYC_MU_SPLIT_DPSIP_TH_CORR;     /*@ LSB:4.883e-4 UNIT:1     NAME:PSIP_MU_SPLIT_CORR REM:My split correction factor dpsip thresholds @*/

 extern unsigned_int16_t              AYC_CTRL_ARBITRATION_RESULT;    /*@ LSB:1        UNIT:1     NAME:YTQARBRESULT REM:indicates which AYC controller has the actual priority of AYC_REQUESTED_YAW_TORQUE @*/   /* 6039:3hmi170604 */
 extern signed_int16_t                AYC_FILTERED_REQ_YT;            /*@ LSB:0.1      UNIT:bar   NAME:FILT_ZUSMOM_OLD  REM:AYC filtered requested yaw torque last loop@*/ /*RBeck060821*/
 extern signed_int16_t                AYC_DYNAMIC_TH_CORR;
#if (AYC_BKST_FOR_MODEL_FILTER)
 extern signed_int32_t                         LAMBDA_YAW_RATE_COEFF;           /*@ LSB:         UNIT:        NAME:LAM_YR_M_COEF REM:temporary variable to store lambda of model yawrate filtering in case of countersteering @*/  /* .#a001KO111202. */
#endif

    /********************************************************/
    /*                  Verification                        */
    /********************************************************/
#if (PDO_CFG & 0x80000)    /* Task 2948: 001LEM170603 */
 extern signed_int16_t PDOVAR_STM_Lf_m_PSIP_d_Vref;     /*@ LSB:7.63e-4  UNIT:deg     NAME:Lf_PSIP_Vref  REM: Calculation of (L_f*PSIP)/V_ref @*/
 extern signed_int16_t PDOVAR_STM_Lr_m_PSIP_d_Vref;     /*@ LSB:7.63e-4  UNIT:deg     NAME:Lr_PSIP_Vref  REM: Calculation of (-L_r*PSIPP)/V_ref @*/

 extern signed_int16_t PDOVAR_STM_SLIP_ANG_LIM_Cf;      /*@ LSB:7.63e-4  UNIT:deg     NAME:ALPHA_LIM_Cf  REM: Calculation of Front Slip Angle Limit, Fflatlim*(1/C_F) @*/

 extern signed_int16_t PDOVAR_STM_LAT_FORCE_MAX;        /*@ LSB:2        UNIT:N       NAME:Lat_F_Max     REM: The Maximum Lateral Force (transfered from wheels to the road) dependent on friction coefficient @*/

 extern signed_int16_t PDOVAR_STM_SLIP_ANG_F_TYRE;      /*@ LSB:7.63e-4  UNIT:deg     NAME:ALPHA_F       REM: Slip angle on front tyre @*/
 extern signed_int16_t PDOVAR_STM_SLIP_ANG_R_TYRE;      /*@ LSB:7.63e-4  UNIT:deg     NAME:ALPHA_R       REM: Slip angle on rear tyre  @*/

 extern signed_int16_t PDOVAR_STM_SLIP_ANG_F_TEMP;      /*@ LSB:7.63e-4  UNIT:deg     NAME:ALPHA_F_TMP   REM: Slip angle on front tyre, redundant @*/

 extern signed_int16_t PDOVAR_STM_SLIP_ANG_MAX_MU;      /*@ LSB:7.63e-4  UNIT:deg     NAME:ALPHA_MAX     REM: Maximum Alpha computed from friction coefficient @*/

 extern signed_int16_t PDOVAR_STM_LAT_FORCE_FRONT;      /*@ LSB:2        UNIT:N       NAME:Lat_F_Front   REM: Front Lateral Force (transfered from wheels to the road) after Peak-filter @*/
 extern signed_int16_t PDOVAR_STM_LAT_FORCE_REAR;       /*@ LSB:2        UNIT:N       NAME:Lat_F_Rear    REM: Rear Lateral Force (transfered from wheels to the road) @*/

 extern signed_int16_t PDOVAR_STM_BetaP_Ref;            /*@ LSB:2.865e-3 UNIT:deg/s   NAME:BetaP_Ref     REM: Reference Slip Angle Rate @*/

 extern signed_int16_t PDOVAR_STM_PSIPP_REF_OLD;        /*@ LSB:0.4092   UNIT:deg/s/s NAME:Yaw_Accel     REM: Yaw acceleration of previous loop @*/

 extern signed_int16_t PDOVAR_STM_IPSIP_SET;            /*@ LSB:2.865e-3 UNIT:deg/s   NAME:Psip_Set      REM: Yaw rate reset value @*/
 extern signed_int16_t PDOVAR_STM_IBETA_SET;            /*@ LSB:1.526e-3 UNIT:deg     NAME:Beta_Set      REM: Slip angle reset value @*/

 extern unsigned_int16_t PDOVAR_STM_RESET_AYC_CONTROL;  /*@ LSB:1        UNIT:bit     NAME:AYC_RESET     REM: Reset of AYC Control flag @*/

 extern signed_int16_t PDOVAR_STM_YAW_RATE_VAL;         /*@ LSB:2.865e-3 UNIT:deg/s   NAME:YAW_RATE_VAL  REM: @*/
 extern signed_int16_t PDOVAR_STM_LAMBDA;               /*@ LSB:         UNIT:        NAME:STM_LAMBDA    REM: @*/

#endif                     /* Task 2948: 001LEM170603 */

/******************************************************************************
 * 'M A K R O - D E C L A R A T I O N S'                                      *
 ******************************************************************************/

/* --> Task 3861: 001LEM040603 */
#define Get_stm_model_reset()                   (AYC_STM_BITS.MODEL_RESET)
#define Set_stm_model_reset(x)                  (AYC_STM_BITS.MODEL_RESET = (x))

#define Get_stm_model_reset_back()              (AYC_STM_BITS.MODEL_RESET_BACK)
#define Set_stm_model_reset_back(x)             (AYC_STM_BITS.MODEL_RESET_BACK = (x))

#define Get_stm_beta_reset_prohibited()         (AYC_STM_BITS.BETA_RESET_PROHIBITED)
#define Set_stm_beta_reset_prohibited(x)        (AYC_STM_BITS.BETA_RESET_PROHIBITED = (x))

#define Get_stm_backsteer_for_model()           (AYC_STM_BITS.BACKSTEER_FOR_MODEL)
#define Set_stm_backsteer_for_model(x)          (AYC_STM_BITS.BACKSTEER_FOR_MODEL = (x))

#define Get_stm_counter_reset_for_adapt_C_R()   (AYC_STM_BITS.COUNTER_RESET_FOR_ADAPT_C_R)
#define Set_stm_counter_reset_for_adapt_C_R(x)  (AYC_STM_BITS.COUNTER_RESET_FOR_ADAPT_C_R = (x))

#define Get_stm_adaptation_of_C_R_possible()    (AYC_STM_BITS.ADAPTION_OF_C_R_POSSIBLE)
#define Set_stm_adaptation_of_C_R_possible(x)   (AYC_STM_BITS.ADAPTION_OF_C_R_POSSIBLE = (x))

#define Get_stm_bkst_for_model_filter()         (AYC_STM_BITS.BKST_FOR_MODEL_FILTER)
#define Set_stm_bkst_for_model_filter(x)        (AYC_STM_BITS.BKST_FOR_MODEL_FILTER = (x))
#define Int_max                                 32767
#define Get_fric_running()                      1
#define Get_ctrl_ayc_in_cycle_dpsip()           1


/* <-- Task 3861: 001LEM040603 */

/******************************************************************************
 * 'F U N C T I O N - P R O T O T Y P E S'                                    *
 ******************************************************************************/

 extern void CALC_AYC_YAW_RATE_REF (void);
 extern void CALC_AYC_YAW_RATE_REF_2 (void);


/*------------------------------------------------------------------------*/
/*                     PARAMETER TABLE LENGTH                             */
/*------------------------------------------------------------------------*/
#define Esm_lat_force_delay_tablen    4


/*------------------------------------------------------------------------*/   /* --> .!A002RE080699. */
/*                       NUMERIC SCALING FACTORS                          */
/*------------------------------------------------------------------------*/   /* <-- .!003MS090199. */
#define G1_alphaf                       (signed_int16_t)2
#define G2_alphaf                       (signed_int16_t)2
#define G3_alphaf                       (signed_int16_t)(-8)
#define G2_alphaf_max                   (signed_int16_t)(-128)
#define G1_alphar                       (signed_int16_t)2
#define G2_alphar                       (signed_int16_t)(-8)
#define G1_fflat                        (signed_int16_t)(-16384)
#define G1_frlat                        (signed_int16_t)(-16384)
#define G1_betap                        (signed_int16_t)(-64)
#define G2_betap                        (signed_int16_t)(-64)
#define G3_betap                        (signed_int16_t)(-64)
#define G1_psipp                        (signed_int16_t)(-16384)
#define G2_psipp                        (signed_int16_t)(-16384)
#define G1_fflatlim                     (signed_int16_t)(-256)
#define G1_alphaflim                    (signed_int16_t)(-4096)
#define G1_fflatkorr                    (signed_int16_t)(-16384)
#define G1_beta_int                     (signed_int16_t)(-16384)
#define G1_psipset                      (signed_int16_t)32
#define G1_betaset                      (signed_int16_t)(-8192)
#define G2_betaset                      (signed_int16_t)(-256)
#define G3_betaset                      (signed_int16_t)(-16)


#define Esm_overswing_scale_factor      (signed_int16_t)256
#define Yaw_rate_scale_fac 4096                   /* Scaling factor */         /* .!A001RE150799. */

#if 0
/* Scaling factors from physical units to integer */
#define Esm_fg_v                        360        m/sec
#define Esm_fg_delta                    655.34     Grad
#define Esm_fg_my                       100        1
#define Esm_fg_psip                     349.04     Grad/sec
#define Esm_fg_beta                     655.34     Grad
#define Esm_fg_psipp                    2.443      Grad/sec/sec
#define Esm_fg_betap                    5.454      Grad/sec
#define Esm_fg_alphaf                   1311       Grad
#define Esm_fg_alphar                   1311       Grad
#define Esm_fg_F_f                      0.008738   N*57.3
#define Esm_fg_F_f_lat_lim              0.008738   N*57.3
#define Esm_fg_F_r                      0.006553   N*57.3
#define Esm_fg_T                        1.969e+6   sec                  /* <-- .!A002RE080699. */
#endif                                                                         /* --> .!003MS090199. */


/*------------------------------------------------------------------------*/
/*                 COMMON CONSTANTS AND DERIVATES                         */
/*------------------------------------------------------------------------*/
/*#define Yaw_rate_scale_fac 4096*/         /* Scaling factor */                   /* .#A005DUI150799. */

#define Esm_max_overswing_of_psip       (signed_int16_t)((Esm_overswing_scale_factor*100)/130)

#define Esm_freq_low                    (signed_int16_t)(Yaw_rate_scale_fac*2.2487) /*Cut off frequency*/ /*.#001RSC311001. XXms conversion*/
#define Esm_freq_high                   (signed_int16_t)(Yaw_rate_scale_fac*0.9474) /*Cut off frequency*/ /*.#001RSC311001. XXms conversion*/
#define Esm_lambda_time                 (signed_int16_t)(6.283*Loop_time_sec*1024)
#define Esm_lambda_low                  (signed_int16_t)(Yaw_rate_scale_fac*0.91)
#define Esm_lambda_high                 (signed_int16_t)(Yaw_rate_scale_fac*0.96)
#define Esm_lam_yaw_rate_ref            (signed_int16_t)(Yaw_rate_scale_fac*0.7)
#define Esm_freq_yaw_rate_ref           9.7442 /*Cut off frequency*/ /*.#001RSC311001. XXms conversion*/
#define Esm_min_dpsip_to_filter         (signed_int16_t)150     /* 0.5 Grad/sec */
#define Esm_lambda_yref_gain            (signed_int16_t)45      /* 1/(0.0375*Yaw_rate_scale_fac)/(300/(57.3*Steer_angle_p_scale) */
#define Esm_freq_yref_gain              (signed_int16_t)7026    /* 1/(Esm_freq_low-Esm_freq_high)/(400/57.3*Steer_angle_p_scale) */  /*.#001RSC311001. XXms conversion*/

#define Esm_debounce_time               (unsigned_char_t)(0.125/Loop_time_sec)

#define Gc1_tint                        1968752.9
#define Esm_c1_tint                     (signed_int16_t)((Gc1_tint*Loop_time_sec)/2.)


#if 0
    /*-------------------------------------------------------------------*/
    /*                   NUMERICAL SCALING FACTORS                       */
    /*-------------------------------------------------------------------*/    /* <-- .!003MS090199. */

    #define Gc1_alphaf                  10814.683                         /* --> .!A002RE080699. */
    #define Gc1_alphar                  10814.683
    #define Gc1_fflat                   0.10922667
    #define Gc1_frlat                   0.08192
    #define Gc1_betap                   14380449
    #define Gc2_betap                   19173933
    #define Gc1_psipp                   4581291.6
    #define Gc2_psipp                   6108388.9
    #define Gc1_fflatlim                0.022368939
    #define Gc1_alphaflim               6.144e+008
    #define Gc1_fflatkorr               0.10922667
    #define Gc1_psipset                 39.267016
    #define Gc1_betaset                 6.144e+008
    #define Gc2_betaset                 1677.6704
    #define Gc3_betaset                 10814.683
    #define Gc1_alphaf_max              1310.68
    #define Gc2_alphaf_max              1677.6704



    /*-------------------------------------------------------------------*/    /* --> .!003MS090199. */
    /*             CAR SPECIFIC_CONSTANTS AND DERIVATES                  */
    /*-------------------------------------------------------------------*/


    #define Esm_psip_set_korr           1.1   /*for P23 with value 1.0 RE 08.06.99*/

    /* Common parameters for calculation of factors */

    #define Fc1_alphaf                  (-Vhc_l_f)
    #define Fc1_alphar                  Vhc_l_r
    #define Fc1_fflat                   Vhc_c_f
    #define Fc1_frlat                   Vhc_c_r
    #define Fc1_betap                   (1/Vhc_vehicle_mass)
    #define Fc2_betap                   (1/Vhc_vehicle_mass)
    #define Fc1_psipp                   (Vhc_l_f/Vhc_vehicle_theta)
    #define Fc2_psipp                   (-Vhc_l_r/Vhc_vehicle_theta)
    #define Fc1_fflatlim                ((Vhc_vehicle_mass*Mss_to_g*Vhc_l_r)/((Vhc_l_r+Vhc_l_f)*Grad_to_rad))
    #define Fc1_alphaflim               (1/Vhc_c_f)
    #define Fc1_fflatkorr               (Esm_c_f_korr*Vhc_c_f)
    #define Fc1_psip_set                (Mss_to_g*Esm_psip_set_korr/Grad_to_rad)
    #define Fc1_beta_set                ((1-Esm_c_f_korr)*Vhc_l_f/(Vhc_c_r*Vhc_l_r))
    #define Fc2_beta_set                (Fc2_alphamax*Esm_c_f_korr*Vhc_c_f*Vhc_l_f)/(Vhc_c_r*Vhc_l_r)
    #define Fc3_beta_set                Vhc_l_r

    #define Esm_c_f_korr                0.1



    #define Esm_c1_alphaf               (signed_int16_t)(Gc1_alphaf * Fc1_alphaf)
    #define Esm_c1_alphar               (signed_int16_t)(Gc1_alphar * Fc1_alphar)
    #define Esm_c1_fflat                (signed_int16_t)(Gc1_fflat * Fc1_fflat)
    #define Esm_c1_frlat                (signed_int16_t)(Gc1_frlat * Fc1_frlat)
    #define Esm_c1_betap                (signed_int16_t)(Gc1_betap * Fc1_betap)
    #define Esm_c2_betap                (signed_int16_t)(Gc2_betap * Fc2_betap)
    #define Esm_c1_psipp                (signed_int16_t)(Gc1_psipp * Fc1_psipp)
    #define Esm_c2_psipp                (signed_int16_t)(Gc2_psipp * Fc2_psipp)
    #define Esm_c1_fflatlim             (signed_int16_t)(Gc1_fflatlim * Fc1_fflatlim)
    #define Esm_c1_alphaflim            (signed_int16_t)(Gc1_alphaflim * Fc1_alphaflim)
    #define Esm_c1_fflatkorr            (signed_int16_t)(Gc1_fflatkorr * Fc1_fflatkorr)
    #define Esm_c1_psipset              (signed_int16_t)(Gc1_psipset * Fc1_psip_set)
    #define Esm_c1_alpha_max            (signed_int16_t)(Gc1_alphaf_max * Fc1_alphamax)
    #define Esm_c2_alpha_max            (signed_int16_t)(Gc2_alphaf_max * Fc2_alphamax)
    #define Esm_c1_betaset              (signed_int16_t)(Gc1_betaset * Fc1_beta_set)
    #define Esm_c2_betaset              (signed_int16_t)(Gc2_betaset * Fc2_beta_set)
    #define Esm_c3_betaset              (signed_int16_t)(Gc3_betaset * Fc3_beta_set)

    /* filter constant for peak filter of lateral force at front axle */       /* --> .!003MS090199. */
    #define Esm_max_delta_fflat_slow    (signed_int16_t)(0.5*Vhc_c_f*Esm_fg_F_f)
    #define Esm_max_delta_fflat_quick   (signed_int16_t)(0.1*Vhc_c_f*Esm_fg_F_f) /* <-- .!A002RE080699. */
#endif

 /******************************************************************************
 Extern Name: LABS_F
 Description: Calculates absolute value (long integer)
 ******************************************************************************/
 __SFL_INLINE__ signed_int32_t LABS_F (signed_int32_t);


 signed_int16_t AYC_PEAK_FILTER (signed_int16_t signal_actual,
                                 signed_int16_t signal_old,
                                 unsigned_int16_t signal_delta_max);

#endif
