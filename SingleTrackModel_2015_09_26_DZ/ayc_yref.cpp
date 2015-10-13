/*
***************************************************************************************************
INCLUDE-FILES
*/

#include "ayc_yref.h"


/*
***************************************************************************************************
LOCAL DEFINITIONS
*/

#ifndef AYC_YREF_VERIFICATION
#define AYC_YREF_VERIFICATION 0
#endif

/*
***************************************************************************************************
DEFINITIONS
*/
signed_int16_t ESM_C2_PSIPP;
signed_int16_t ESM_C1_ALPHAFLIM;
signed_int16_t ESM_C1_FFLATKORR;
signed_int16_t ESM_C1_BETAP;
signed_int16_t ESM_C1_BETASET;
signed_int16_t ESM_C1_FFLAT;
signed_int16_t ESM_C1_FFLATLIM;
signed_int16_t ESM_C1_FRLAT;
signed_int16_t ESM_C1_PSIPP;
signed_int16_t ESM_C2_BETAP;
signed_int16_t ESM_C2_BETASET;
signed_int16_t ESM_C1_ALPHAF;
signed_int16_t ESM_C1_ALPHAR;
signed_int16_t ESM_C1_PSIPSET;
signed_int16_t ESM_C3_BETASET;
signed_int16_t MODPR_SCALED_EG;
signed_int16_t MODPR_SCALED_WHEELBASE;
signed_int16_t VS_DV_TH_FA;
signed_int16_t VS_DV_TH_RA;
signed_int16_t VS_PSIP_CORR_FA;
signed_int16_t VS_PSIP_CORR_RA;
signed_int16_t VS_PSIP_N_FA;
signed_int16_t VS_PSIP_N_RA;
signed_int16_t VS_SCALED_TRACK_FA;
signed_int16_t VS_SCALED_TRACK_RA;
signed_int16_t VREF_TRACK_WIDTH;
signed_int16_t DPSIP_LAT_GRAD_CORR_FAC2;
signed_int16_t ADAPT_C_R_DENUM_1;
signed_int16_t ADAPT_C_R_NUM;
signed_int16_t ADAPT_C_R_DENUM_3;
signed_int16_t ADAPT_C_R_DENUM_4;
signed_int16_t ADAPT_C_R_NUM_1;
signed_int16_t ESM_MAX_DELTA_FFLAT_Y_MS[2];
signed_int16_t ESM_LAT_FORCE_DELAY_VEL_TAB[4];
signed_int16_t ESM_LAT_FORCE_DELAY_FCONST_TAB[4];

unsigned_char_t                        AYC_SINGLE_TRACK_MODEL_STATE;
signed_int16_t                         AYC_SLIP_ANGLE_REF;              /*@ LSB:1.526e-3 UNIT:deg     NAME:SLP_ANG_REF  REM:side slip of single track model @*/
signed_int16_t                         AYC_YAW_RATE_MODEL;              /*@ LSB:2.865e-3 UNIT:deg/s   NAME:YAWRATE_MODL REM:yawrate of single track model @*/

signed_int16_t                         AYC_SLIP_ANGLE_RATE_REF;         /*@ LSB:0.18336  UNIT:deg/s   NAME:SLP_ANG_RATE REM:side slip acceleration of single track model kept in mind for Runge-Kutta Integration @*/
signed_int16_t                         AYC_SLIP_ANGLE_BACK;             /*@ LSB:1.526e-3 UNIT:deg     NAME:SLP_ANG_BACK REM:saved side slip of single track model for model-reset @*/
signed_int16_t                         AYC_YAW_RATE_BACK;               /*@ LSB:2.865e-3 UNIT:deg/s   NAME:YAWRATE_BACK REM:saved yawrate of single track model for model-reset @*/
signed_int16_t                         AYC_FF_LAT_OLD;                  /*@ LSB:2        UNIT:N       NAME:FF_LAT_OLD   REM:stored value of lateral force at the front axle @*/

signed_int16_t                         IALPHA_F_BACK;
unsigned_char_t                        AYC_ESTIMATED_MY;
unsigned_char_t                        ESM_DEBOUNCE_TIMER;
signed_int16_t                          AYC_FILTERED_YAW_RATE;

signed_char_t                           AYC_FILTERED_LATERAL_ACC_FA;    /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCF  REM:ayc filtered lateral acceleration at front axle @*/
signed_char_t                           AYC_FILTERED_LATERAL_ACC_RA;    /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCR  REM:ayc filtered lateral acceleration at rear axle @*/
signed_char_t                           AYC_FILTERED_LATERAL_ACC_COG;   /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCC  REM:ayc filtered lateral acceleration at center of gravity @*/
signed_char_t                           AYC_CUR_LATERAL_ACCELERATION;   /*@ LSB:0.0981  UNIT:m/ss   NAME:FLATACC_CUR REM:calibrated and filtered lat.acceleration @*/      /* .#a001KO191102. */
signed_int16_t                          AYC_PRESSURE_MAIN_CYLINDER;     /*@ LSB:0.01    UNIT:bar    NAME:APRESMAIN  REM:ayc pressure of main cylinder @*/
signed_int16_t                          AYC_FILTERED_STEER_ANGLE;       /*@ LSB:1.526e-3 UNIT:deg   NAME:AFSTANGLE  REM:ayc filtered steer angle @*/
signed_int16_t                          AYC_FILTERED_STEER_ANGLE_RATE;  /*@ LSB:0.04375 UNIT:deg/s  NAME:AFSTANGLEP REM:ayc filtered steer angle rate @*/

signed_int16_t                          AYC_DRV_REQ_STEER_ANGLE;        /*@ LSB:1.526e-3 UNIT:deg   NAME:AFSWADRV   REM:driver requested steer angle @*/          /* --> 5587:UBauer210703 */
signed_int16_t                          AYC_DRV_REQ_STEER_ANGLE_RATE;   /*@ LSB:0.04375 UNIT:deg/s  NAME:AFSWADRVP  REM:driver requested*/
signed_int16_t                         STM_LAT_FORCE_REAR;

signed_int16_t                         AYC_DT_CONTROL_DEVIATION;     /*@ LSB:2.865e-3 UNIT:deg/ss  NAME:DT_CTRL_DEV  REM:derivation of ayc control deviation @*/ /* .#003gae120399. */
signed_int16_t                         AYC_YAW_ACC_REF;              /*@ LSB:0.4092   UNIT:deg/s/s NAME:YAW_ACC_REF  REM:yaw acceleration of single track model @*/
signed_int16_t                         AYC_SLIP_ANGLE_RATE_RA;

signed_int16_t                         AYC_YAW_RATE_REF;
signed_int16_t                         AYC_REF_YAW_RATE_FROM_SA;               /*!< @ASAP_NAME   REFYRSA @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   reference yaw rate derived from steer angle */
signed_int16_t                         AYC_REF_YAW_RATE_FROM_SA_FIL;           /*!< @ASAP_NAME   REFYRSAF @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   filtered reference yaw rate derived from steer angle */
signed_int16_t                         UNCALIBRATED_YAW_RATE;                  /*!< @ASAP_NAME   RAWYR @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   uncalibrated and not filtered yaw rate */
signed_int16_t                         UNCALIBRATED_YAW_RATE_FIL;              /*!< @ASAP_NAME   RAWYRFL @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   uncalibrated but filtered yaw rate */
signed_int16_t                         YAW_RATE;                               /*!< @ASAP_NAME   YR @UNIT   deg/s @LSB   0.00286 @MIN   @MAX   @OFFSET   @brief   calibrated but not filtered yaw rate */
signed_int16_t                         UNCALIBRATED_YAW_RATE_LBO;

signed_int16_t                AYC_DBETAP_OLD;                 /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPRA_OLD  REM:BETAP rear axle of last loop @*/
signed_int16_t                AYC_CONTROL_DEVIATION_OLD;      /*@ LSB:2.865e-3 UNIT:deg/s NAME:CTRL_DEV_OLD REM:AYC control deviation of last loop @*/
signed_int16_t                AYC_REQUESTED_YAW_TORQUE_OLD;   /*@ LSB:0.1      UNIT:bar     NAME:ZUSMOM_OLD       REM:AYC requested yaw torque last loop@*/

unsigned_int16_t              AYC_SLIP_ANGLE_RATE_RA_ABS;     /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPRA_ABS  REM:BETAP rear axle absolute value @*/
signed_int16_t                AYC_DPSIP_TH_IN_CTRL;           /*@ LSB:2.865e-3 UNIT:deg/s NAME:DPSIPIN      REM:Yawrate deviation threshold for entering control @*/
signed_int16_t                AYC_BETAP_TH_IN_CTRL;           /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPIN      REM:Slip angle rate threshold for entering control @*/
signed_int16_t                AYC_DPSIP_TH_OUT_CTRL;          /*@ LSB:2.865e-3 UNIT:deg/s NAME:DPSIPOUT     REM:Yawrate deviation threshold for leaving control @*/
signed_int16_t                AYC_BETAP_TH_OUT_CTRL;          /*@ LSB:2.865e-3 UNIT:deg/s NAME:BETAPOUT     REM:Slip angle rate threshold for leaving control @*/
signed_int16_t                AYC_K_BETAP;                    /*@                         NAME:KBETAP       REM:Gain factor for slip angle rate control @*/
signed_int16_t                AYC_K_DPSIP;                    /*@                         NAME:KDPSIP       REM:Gain factor for dpsip-torque @*/
signed_int16_t                AYC_K_DPSIP_DT;                 /*@                         NAME:KDPSIP_DT    REM:Gain factor for DT-part dpsip-torque @*/
signed_int16_t                AYC_STORED_LGA;                 /*@ LSB:0.014    UNIT:deg   NAME:STORED_LGA   REM:keep old value of lateral gradient angle @*/
signed_int16_t                AYC_MU_SPLIT_DPSIP_TH_CORR;     /*@ LSB:4.883e-4 UNIT:1     NAME:PSIP_MU_SPLIT_CORR REM:My split correction factor dpsip thresholds @*/
unsigned_int16_t              AYC_CTRL_ARBITRATION_RESULT;    /*@ LSB:1        UNIT:1     NAME:YTQARBRESULT REM:indicates which AYC controller has the actual priority of AYC_REQUESTED_YAW_TORQUE @*/   /* 6039:3hmi170604 */
signed_int16_t                AYC_FILTERED_REQ_YT;            /*@ LSB:0.1      UNIT:bar   NAME:FILT_ZUSMOM_OLD  REM:AYC filtered requested yaw torque last loop@*/ /*RBeck060821*/
signed_int16_t                AYC_DYNAMIC_TH_CORR;
ayc_stm_bits_t            AYC_STM_BITS;                   /*@ NAME:STM_BIT      REM:AYC single track model bits @*/
ayc_friction_bits_t       AYC_FRICTION_BITS;

__SFL_INLINE__ signed_int32_t LABS_F (signed_int32_t in_value_l)
    #ifdef PRQA_SIZE_T
    #pragma PRQA_NO_SIDE_EFFECTS LABS_F
    #endif  /* PRQA_SIZE_T */
    {
      signed_int32_t output_l;

      if (in_value_l >= 0)
      {
        output_l = in_value_l;
      }
      else if (in_value_l <= -Long_max)
      {
        output_l = Long_max;
      }
      else
      {
        output_l = -in_value_l;
      }
      return(output_l);
    } /* LABS_F */

signed_int16_t AYC_PEAK_FILTER (signed_int16_t signal_actual,
                                    signed_int16_t signal_old,
                                    unsigned_int16_t signal_delta_max)
    {
       if(   (signal_actual - signal_old) > signal_delta_max)
       {
          signal_old += (signed_int16_t)signal_delta_max;
       }
       else
       {
          if( (signal_old - signal_actual) > signal_delta_max)
          {
             signal_old -= (signed_int16_t)signal_delta_max;
          }
          else
          {
             signal_old = signal_actual;
          }
       }
       return(signal_old);
    }

__SFL_INLINE__ signed_int16_t INTLIM (signed_int32_t input)
    #ifdef PRQA_SIZE_T
    #pragma PRQA_NO_SIDE_EFFECTS INTLIM
    #endif  /* PRQA_SIZE_T */
    {
      signed_int16_t output;

      if (input > Int_max)
      {
        output = Int_max;
      }
      else if (input < Int_min)
      {
        output = Int_min;
      }
      else
      {
        output = (signed_int16_t)input;
      }
      return(output);
    }

    /******************************************************************************
    Extern Name: INTERPOL_S16
    Description: Linear interpolation for signed_int16_t

    Linear interpolation in two dimensional datafields. Datapoints do not have
    to be equidistant.

    No extrapolation, x_values outside range of x_tab are limited.
    x_value < x_tab[0]          results in y_tab[0]
    x_value > x_tab[tab_len-1]  results in y_tab[tab_len-1]

    Difference between two X-datapoints must be smaller than Intmax.

        y_tab[0]|--o
                |  |
                |  |
                |  |
             [1]|--|--o
                |  |  |\
                |  |  | \
           Y----|--|--|--*
                |  |  |  |\
                |  |  |  | \
                |  |  |  |  \
             [2]|--|--|--|---o
                |  |  |  |   |
                |  |  |  |   |
             [3]|--|--|--|---|--------------o
                |__|__|__|___|______________|_____
             x_tab[0][1] |  [2]            [3]
                         |
                     x_value

    Arguments:
      x_value     x-value, for which a corresponding y-value is searched
      x_tab       Array of x-values of the supporting points
      y_tab       Array of the corresponding y-values
      tab_len     Number of supporting points
    Return value: Interpolated y-value
    ******************************************************************************/
signed_int16_t INTERPOL_S16(signed_int16_t x_value,
                                const signed_int16_t x_tab[],
                                const signed_int16_t y_tab[],
                                unsigned_char_t tab_len)
    {
       signed_int32_t  i;
       signed_int32_t  y_value;

       if (tab_len < 2)
       {
          /* tab_len must be greater or equal 2!!! */
    #if (CFG_INTERNAL_SIGNAL_MONITORING)
          SET_SW_BUG(Bfu_mathfunc_tablen_to_small);
    #endif
          y_value = 0;
       }
       else if (x_value <= x_tab[0])
       {
          /* x_value below lower bound */
          y_value = y_tab[0];
       }
       else if (x_value >= x_tab[tab_len-1])
       {
          /* x_value above upper bound */
          y_value = y_tab[tab_len-1];
       }
       else
       {
          /* Interpolation */
          for (i = tab_len-2; x_tab[i] >= x_value; i--)
          {
             /* nothing to do */
          }

          y_value = INTERPOL(x_value, x_tab[i], y_tab[i], x_tab[i+1], y_tab[i+1]);
       }

       return (signed_int16_t)y_value;
    }


__SFL_INLINE__ signed_int16_t DABS_F (signed_int16_t in_value)
    #ifdef PRQA_SIZE_T
    #pragma PRQA_NO_SIDE_EFFECTS DABS_F
    #endif  /* PRQA_SIZE_T */
    {
      signed_int16_t output;

      if (in_value >= 0)
      {
        output = in_value;
      }
      else if (in_value <= -Int_max)
      {
        output = Int_max;
      }
      else
      {
        output = -in_value;
      }
      return(output);
    } /* DABS_F */

__SFL_INLINE__ signed_int16_t DSIGN_F (signed_int16_t in_value)
    #ifdef PRQA_SIZE_T
    #pragma PRQA_NO_SIDE_EFFECTS DSIGN_F
    #endif  /* PRQA_SIZE_T */
    {
      signed_int16_t output;

      if (in_value >= 0)
      {
        output = 1;
      }
      else
      {
        output = -1;
      }

      return(output);
    } /* DSIGN_F */

__SFL_INLINE__ signed_int32_t LSIGN_F (signed_int32_t in_value)
    #ifdef PRQA_SIZE_T
    #pragma PRQA_NO_SIDE_EFFECTS LSIGN_F
    #endif  /* PRQA_SIZE_T */
    {
      signed_int32_t output;

      if (in_value >= 0)
      {
        output = 1;
      }
      else
      {
        output = -1;
      }
      return(output);
    } /* LSIGN_F */

/******************************************************************************
* Procedure:
*
* Attributes:
*       DEFN_FILE = ayc_yref.c[File];
*       DECL_FILE = ayc_yref.h[File];
*       STRUCTURE_CHART=/mdt1//AYC_MODEL_PROCESSING[SC];
******************************************************************************
* last modification:                                              Date:    by:
*  initial version                                              22.07.98   Dui
*
******************************************************************************/

void CALC_AYC_YAW_RATE_REF (void)
{

   signed_int16_t  psipp_ref_old;   /* storing old value od psipp for runge kutta */
   signed_int32_t  longerg1;
   signed_int32_t  vref_test;       /* Int_max*AYC_REFERENCE_VELOCITY */
   signed_int32_t  longerg2;
   signed_int16_t  ialpha_f;
   signed_int16_t  iF_f;
   signed_int16_t  interg1;
   signed_int16_t  interg2;
   signed_int16_t  interg3;
   signed_int16_t  ibeta_set;
   signed_int16_t  ipsip_set;
   signed_int16_t  Fflatlim;

   /************************************/
   /* actual alpha at the frontal axle */
   /************************************/

   /* if AFS is in car, use the to the front wheel calculated steering request of driver (variable steering ratio) */
   longerg1 = (signed_int32_t)G1_alphaf*AYC_DRV_REQ_STEER_ANGLE;                /* 5587:4:UBauer010803 */

   longerg2 = ((signed_int32_t)Esm_c1_alphaf*AYC_YAW_RATE_MODEL)/(-G3_alphaf);

   vref_test = Int_max*AYC_REFERENCE_VELOCITY;
   if (LABS_F(longerg2) >= vref_test)
   {
      interg1 = Int_max * (signed_int16_t)LSIGN_F(longerg2);
   }
   else
   {
      interg1 = (signed_int16_t)(longerg2 / AYC_REFERENCE_VELOCITY);
   }

   longerg2 = (signed_int32_t)G2_alphaf*AYC_SLIP_ANGLE_REF;

   longerg1 += longerg2 + interg1;
   ialpha_f = INTLIM(longerg1);

   /* filtern des vorderen Schr„glaufwinkels um Verz”gerung im Latschaufbau */
   /* nachzubilden (Filterkonstante ist geschwindigkeitsabh„ngig)           */
   interg1 = AYC_INTPOL2(AYC_REFERENCE_VELOCITY,
                         Esm_lat_force_delay_vel_tab,
                         Esm_lat_force_delay_fconst_tab,
                         Esm_lat_force_delay_tablen);

   IALPHA_F_BACK  = (signed_int16_t)( ( (signed_int32_t)IALPHA_F_BACK * interg1 )
                                      / (signed_int16_t)8192 );
   IALPHA_F_BACK += (signed_int16_t)( ( (signed_int32_t)ialpha_f * ( (signed_int16_t)8192 - interg1 ) )
                                      / (signed_int16_t)8192 );

   ialpha_f = IALPHA_F_BACK;                                                  /* <-- .!050ms240698. */ /* <-- .!003MS090199. */

   /***************************************************************/
   /* calculation of actual possible lateral force at front wheel */
   /***************************************************************/

   /* The Maximum of the lateral force depends on friction coefficient */
   Fflatlim = (signed_int16_t)(((signed_int32_t)Esm_c1_fflatlim*(signed_int16_t)AYC_ESTIMATED_MY) / (-G1_fflatlim)); /* .!003MS090199. */
   interg1  = (signed_int16_t)(((signed_int32_t)Esm_c1_alphaflim*Fflatlim) / (-G1_alphaflim));

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
   PDOVAR_STM_LAT_FORCE_MAX = Fflatlim;
   PDOVAR_STM_SLIP_ANG_LIM_Cf = interg1;         /*  Fflatlim * (1/C_F)  */
#endif

   /* Detect on which part of the lateral force function the actual alpha lies */
   if (DABS_F(ialpha_f) >= interg1)
   {
      /* compute alpha_max from friction coefficient */
      interg2 = Esm_c1_alpha_max + (signed_int16_t)((Esm_c2_alpha_max*(signed_int16_t)AYC_ESTIMATED_MY)/(-G2_alphaf_max));

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
      PDOVAR_STM_SLIP_ANG_MAX_MU = interg2;
#endif

      if (DABS_F(ialpha_f) > interg2)
      {
         AYC_SINGLE_TRACK_MODEL_STATE = 3;
         if (ialpha_f > (signed_int16_t)0)
         {
            interg3 = interg2;
         }
         else
         {
            interg3 = -interg2;
         }
      }
      else
      {
         AYC_SINGLE_TRACK_MODEL_STATE = 2;
         interg3 = ialpha_f;
      }

      if (interg3 > (signed_int16_t)0)
      {
         interg2 = (signed_int16_t)((((signed_int32_t)interg3-interg1)*Esm_c1_fflatkorr) / (-G1_fflatkorr));
         longerg1 = Fflatlim + interg2;
      }
      else
      {
         interg2 = (signed_int16_t)((((signed_int32_t)interg3+interg1)*Esm_c1_fflatkorr) / (-G1_fflatkorr));
         longerg1 = -Fflatlim + interg2;
      }
   }
   else
   {

      longerg1 = ((signed_int32_t)Esm_c1_fflat*ialpha_f) / (-G1_fflat);   /* result is always signed_int16_t */
      AYC_SINGLE_TRACK_MODEL_STATE = 1;
   }

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
   PDOVAR_STM_SLIP_ANG_F_TEMP = ialpha_f;          /* ialpha_f_tmp */
#endif

   interg1 = INTLIM(longerg1);


   /* Peak filter of jumps in the lateral force at the frontal axle which    */
   /* can result from a change of the friction coefficient or if the control */
   /* stops. Maximum difference of alpha_f is = 0.5 Grad/LOOP (same as the   */
   /* maximal approximated steer_angle_rate at the wheels)                   */
/*    interg3=AYC_INTPOL2(AYC_REFERENCE_VELOCITY,                             */   /* --> .!A002RE140600. */
/*                        Esm_max_delta_fflat_x,Esm_max_delta_fflat_y,2);     */   /* <-- .!A002RE140600. */
   interg3 = AYC_INTPOL2(AYC_REFERENCE_VELOCITY,                              /* --> .!A002RE140600. */
                         Esm_max_delta_fflat_x,Esm_max_delta_fflat_y_ms,2); /* <-- .!A002RE140600. */    /* --> .#001RSC311001. XXms conversion */
   interg3 = MUL_DIV_SHORT(interg3, Loop_time_ms, 128);                       /* <-- .#001RSC311001. XXms conversion */

   AYC_FF_LAT_OLD = AYC_PEAK_FILTER(interg1, AYC_FF_LAT_OLD, (unsigned_int16_t)interg3);
   iF_f = AYC_FF_LAT_OLD;

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
   PDOVAR_STM_LAT_FORCE_FRONT = iF_f;
#endif

   /*********************************/
   /* actual alpha at the rear axle */
   /*********************************/
   longerg1 = (signed_int32_t)G1_alphar*AYC_SLIP_ANGLE_REF;
   longerg2 = ((signed_int32_t)Esm_c1_alphar*AYC_YAW_RATE_MODEL) / (-G2_alphar);
   if (LABS_F(longerg2) >= vref_test )
   {
      interg1 = Int_max * (signed_int16_t)LSIGN_F(longerg2);
   }
   else
   {
      interg1 = (signed_int16_t)(longerg2 / AYC_REFERENCE_VELOCITY);
   }

   longerg1 += interg1;

#if (PDO_CFG & 0x80000)    /* Task 2948: 001LEM170603 */                                                      
   PDOVAR_STM_Lr_m_PSIP_d_Vref = interg1;            /*  (-L_r * PSIPP)/V_ref */
   PDOVAR_STM_SLIP_ANG_R_TYRE = INTLIM(longerg1);    /*  ialpha_r  */
#endif


   /* The rear lateral force is not limited */
   STM_LAT_FORCE_REAR = (signed_int16_t)(((signed_int32_t)Esm_c1_frlat*longerg1) / (-G1_frlat));

#if (PDO_CFG & 0x80000)    /* Task 2948: 001LEM170603 */
   PDOVAR_STM_LAT_FORCE_REAR = STM_LAT_FORCE_REAR;
#endif

   /* Slip angle rate */
   longerg1 = ((signed_int32_t)Esm_c1_betap*(-iF_f)) / ((signed_int16_t)(-2)*G1_betap);
   if (LABS_F(longerg1) >= vref_test)
   {
      interg1 = Int_max * (signed_int16_t)LSIGN_F(longerg1);
   }
   else
   {
      interg1 = (signed_int16_t)(longerg1 / AYC_REFERENCE_VELOCITY);
   }

   longerg2 = ((signed_int32_t)Esm_c2_betap*(-STM_LAT_FORCE_REAR)) / ((signed_int16_t)(-2)*G2_betap);
   if (LABS_F(longerg2) >= vref_test)
   {
      interg2 = Int_max * (signed_int16_t)LSIGN_F(longerg2);
   }
   else
   {
      interg2 = (signed_int16_t)(longerg2 / AYC_REFERENCE_VELOCITY);
   }

   interg3 = AYC_YAW_RATE_MODEL / (-G3_betap);
   longerg1 = (((signed_int32_t)interg1*(signed_int16_t)2) + ((signed_int32_t)interg2*(signed_int16_t)2) + interg3);
   interg1 = INTLIM(longerg1);

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
   PDOVAR_STM_BetaP_Ref = interg1;
#endif

   /* Set yaw_acc and beta_vel to zero, if a my-reset has been performed */
   if (Get_stm_model_reset() == true)  /* Task 3861: 001LEM040603 */
   {
      AYC_YAW_ACC_REF = (signed_int16_t)0;
      AYC_SLIP_ANGLE_RATE_REF = (signed_int16_t)0;
      Set_stm_model_reset(false);   /* Task 3861: 001LEM040603 */
   }

   /* copy last value of yaw acceleration to lokal variable */
   psipp_ref_old = AYC_YAW_ACC_REF;

#if (PDO_CFG & 0x80000)                                                         /* Task 2948: 001LEM170603 */
   PDOVAR_STM_PSIPP_REF_OLD = psipp_ref_old;
#endif

   /* Runge-Kutta integration of slip angle */
   longerg1 = (((interg1 + AYC_SLIP_ANGLE_RATE_REF)*Esm_c1_tint) / (-G1_beta_int)) + AYC_SLIP_ANGLE_REF;
   AYC_SLIP_ANGLE_REF     = INTLIM(longerg1);
   AYC_SLIP_ANGLE_RATE_REF = interg1;

   /* Yaw acceleration */
   longerg1 = ((signed_int32_t)Esm_c1_psipp*iF_f) / (-G1_psipp);
   longerg2 = ((signed_int32_t)Esm_c2_psipp*STM_LAT_FORCE_REAR) / (-G2_psipp);
   longerg1 += longerg2;

   AYC_YAW_ACC_REF = INTLIM(longerg1);

   /* Runge-Kutta integration of yaw rate */
   /* longerg1= ((signed_int32_t)AYC_YAW_ACC_REF + psipp_ref_old)/(signed_int16_t)2 + AYC_YAW_RATE_MODEL; */
   longerg1 = ((((signed_int32_t)AYC_YAW_ACC_REF + psipp_ref_old)*Loop_time_ms)/(signed_int16_t)14) + AYC_YAW_RATE_MODEL; /*.#001RSC311001. XXms conversion */
   AYC_YAW_RATE_MODEL = INTLIM(longerg1);

   /* reset value of yaw rate */
   interg2  = (signed_int16_t)((Esm_c1_psipset*(signed_int16_t)AYC_ESTIMATED_MY)/AYC_REFERENCE_VELOCITY);
   longerg1 = ((signed_int32_t)interg2*G1_psipset);
   ipsip_set = INTLIM(longerg1);

   /* reset value of slip angle */
   longerg1 = ((signed_int32_t)Esm_c3_betaset*ipsip_set)/(-G3_betaset);
   if (LABS_F(longerg1) >= vref_test )
   {
      interg1 = Int_max * (signed_int16_t)LSIGN_F(longerg1);
   }
   else
   {
      interg1 = (signed_int16_t)(longerg1 / AYC_REFERENCE_VELOCITY);
   }

   longerg1 = ((signed_int32_t)Fflatlim*Esm_c1_betaset)/(-G1_betaset);
   longerg2 = ((signed_int32_t)Esm_c2_betaset*(signed_int16_t)AYC_ESTIMATED_MY)/(-G2_betaset);


   longerg1 = longerg1 + longerg2 - interg1;
   ibeta_set = INTLIM(longerg1);

   /* Determination of signs */
   if (AYC_YAW_RATE_MODEL < (signed_int16_t)(0) )
   {
      ipsip_set *= (signed_int16_t)-1;
      ibeta_set *= (signed_int16_t)-1;
   }

#if (PDO_CFG & 0x80000)    /* Task 2948: 001LEM170603 */                                                      
   PDOVAR_STM_IPSIP_SET = ipsip_set;
   PDOVAR_STM_IBETA_SET = ibeta_set;
#endif

   interg1 = AYC_YAW_RATE_REF;
  
  AYC_YAW_RATE_REF = (signed_int16_t)Filter_pt1_hz
         (Unfiltered_value(AYC_YAW_RATE_REF),
         Filtered_old_value(interg1),
         Sampling_time_ms(Loop_time_ms),
         Cut_off_freq_hz(Esm_freq_yaw_rate_ref),
         Scaling_factor(Yaw_rate_scale_fac));
  
}
