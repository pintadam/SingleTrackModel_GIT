
#ifndef ayc_init_h_included
#define ayc_init_h_included

/* TYP definitions */
#include "hal_base_type_if.he"
/* AYC RAM definitions */

/******************************************************************************
* 'V A R C O D I N G - D E F I N E S'                                        *
******************************************************************************/

/******************************************************************************
* 'P A R A M E T E R - D E F I N E S'                                        *
******************************************************************************/

/* --> 13751:2herrmann17022005 */
#define Ayc_yr_max_value             (signed_int16_t)   ((75. /*Grad/s*/  /57.3 )/ Yaw_rate_scale )
#define Ayc_yr_max_value_hys         (signed_int16_t)   ((2. /*Grad/s*/  /57.3 )/ Yaw_rate_scale )
/* <-- 13751:2herrmann17022005 */

#if (CFG_AFS)
#define Ayc_delta_steer_max    (unsigned_int16_t)(( 1400*Loop_time_sec*Grad_to_rad)/Steer_angle_p_scale)   /* max. steering rate for differentiation is 1400 deg/s     */
#define Ayc_delta_steer_p_max  (unsigned_int16_t)((10000*Loop_time_sec*Grad_to_rad)/Steer_angle_p_scale)   /* max. steering acc after differentiation is 10000 deg/s/s */
#endif

/* Definition of the yaw rate zero point error after compensation by ECU */
#define Yaw_rate_zero_point_error    (signed_int16_t)((1.0/*Deg/s*//57.3)/Yaw_rate_scale)

#define Num_of_wheels         (4)
/******************************************************************************
* 'C O N S T - D E F I N I T I O N S'                                        *
******************************************************************************/

#define Ayc_sens_lat_acc_available         0x01u
#define Ayc_sens_lat_acc_dt_available      0x02u
#define Ayc_sens_yaw_rate_available        0x04u
#define Ayc_sens_yaw_rate_dt_available     0x08u
#define Ayc_sens_swa_available             0x10u
#define Ayc_sens_swa_dt_available          0x20u
#define Ayc_sens_vel_available             0x40u
#define Ayc_sens_pres_available            0x80u

#if (CFG_AFS)
#define Fading_finished                    (0)
#define Fading_to_vari_swa                 (1)
#define Fading_to_sum_swa                  (2)
#endif

/******************************************************************************
* 'T Y P E - D E C L A R A T I O N S'                                        *
******************************************************************************/

typedef enum
{
   Ayc_sens_check_unavailable = 0,              /* no sensor signal available */
   Ayc_sens_check_vel,                          /* velocity available */
   Ayc_sens_check_vel_la,                       /* velocity and lateral acceleration available */
   Ayc_sens_check_vel_la_yr,                    /* velocity, lateral acceleration and yaw rate available */
   Ayc_sens_check_vel_la_yr_swadt,              /* velocity, lateral acceleration, yaw rate and steering wheel velocity available */
   Ayc_sens_check_all_ayc,                      /* all ayc sensor signals available (applies only to sensors in disable check) */
   Ayc_sens_check_all                           /* all sensors signals available (applies only to sensors in disable check) */
} sensor_status_t;

extern sensor_status_t                         AYC_SENSOR_DISABLE_CHECK;       /*@ LSB: UNIT: NAME:SENSCHECK   REM:Availability level of ayc sensors @*/

/******************************************************************************
* 'B I T - S T R U C T U R E S'                                              *
******************************************************************************/

/* --> 13751:2herrmann17022005 */
typedef struct
{
   unsigned int            YR_REACHED_MAX_VALUE        : 1;  /*@ NAME:YR_MAX_VAL    REM:YR sensor reached maximum value @*/
   unsigned int            YR_CONFIDENCE_LEVEL         : 1;  /*@ NAME:YR_Conf_Level REM:YR sensor confidence level active @*/
   unsigned int            LAT_ACC_SIGNAL_DISTURBED    : 1;  /*@ NAME:LatAcc_Disturbed REM: LatAcc sensor signal is disturbed @*/
   unsigned int            SA_CONFIDENCE_LEVEL         : 1;  /*@ NAME:SA_Conf_Level REM:SA sensor confidence level active @*/
   unsigned int            BIT4                        : 1;  /*@ NAME: REM: @*/
   unsigned int            BIT5                        : 1;  /*@ NAME: REM: @*/
   unsigned int            BIT6                        : 1;  /*@ NAME: REM: @*/
   unsigned int            BIT7                        : 1;  /*@ NAME: REM: @*/
} ayc_sensor_state_t;
extern ayc_sensor_state_t    AYC_SENSOR_STATE_BITS;                /*@ NAME:AYC_SEN_STATE   REM:AYC sensor status bits @*/


/* <-- 13751:2herrmann17022005 */

/******************************************************************************
* 'C H A R A C T E R - V A R I A B L E S'                                    *
******************************************************************************/

extern unsigned_char_t                         AYC_SENSOR_AVAILABILITY;        /*@ LSB: UNIT:  NAME:AYCSENSAV       REM:Availability of sensors used in ayc @*/
extern unsigned_char_t                         AYC_INIT_PARA_CALCULATED;       /*@ LSB: UNIT:  NAME:AYCESMPARA_IO   REM:State if bikemodel parameter calculation is done @*/

/******************************************************************************
* 'I N T E G E R - V A R I A B L E S'                                        *
******************************************************************************/

/* >>> .!A001rl070302. */
extern signed_char_t                           AYC_FILTERED_LATERAL_ACC_FA;    /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCF  REM:ayc filtered lateral acceleration at front axle @*/
extern signed_char_t                           AYC_FILTERED_LATERAL_ACC_RA;    /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCR  REM:ayc filtered lateral acceleration at rear axle @*/
extern signed_char_t                           AYC_FILTERED_LATERAL_ACC_COG;   /*@ LSB:0.0981  UNIT:m/ss   NAME:AFLATACCC  REM:ayc filtered lateral acceleration at center of gravity @*/
extern signed_char_t                           AYC_CUR_LATERAL_ACCELERATION;   /*@ LSB:0.0981  UNIT:m/ss   NAME:FLATACC_CUR REM:calibrated and filtered lat.acceleration @*/      /* .#a001KO191102. */
extern signed_int16_t                          AYC_PRESSURE_MAIN_CYLINDER;     /*@ LSB:0.01    UNIT:bar    NAME:APRESMAIN  REM:ayc pressure of main cylinder @*/
extern signed_int16_t                          AYC_FILTERED_STEER_ANGLE;       /*@ LSB:1.526e-3 UNIT:deg   NAME:AFSTANGLE  REM:ayc filtered steer angle @*/
extern signed_int16_t                          AYC_FILTERED_STEER_ANGLE_RATE;  /*@ LSB:0.04375 UNIT:deg/s  NAME:AFSTANGLEP REM:ayc filtered steer angle rate @*/

extern signed_int16_t                          AYC_DRV_REQ_STEER_ANGLE;        /*@ LSB:1.526e-3 UNIT:deg   NAME:AFSWADRV   REM:driver requested steer angle @*/          /* --> 5587:UBauer210703 */
extern signed_int16_t                          AYC_DRV_REQ_STEER_ANGLE_RATE;   /*@ LSB:0.04375 UNIT:deg/s  NAME:AFSWADRVP  REM:driver requested steering wheel angle rate @*/     /* <-- 5587:UBauer210703 */

#if (CFG_AYC_FREQ_STEER_MANEUVER)                                                     /* -> 202043:1Suganos021008 */
 extern signed_int16_t                          AYC_STEERING_WHEEL_ANGLE;       /*@ LSB:0.04375 UNIT:deg    NAME:ASSWA      REM:ayc calibrated but not filtered steering wheel angle @*/
#endif /* CFG_AYC_FREQ_STEER_MANEUVER */

#if (CFG_SENSOR_CLUSTER_ICM)
extern unsigned_int16_t                        AYC_FSTANGLE_ERROR_AMPLITUDE;   /*@ LSB:1.526e-3 UNIT:deg   NAME:ICMSWAERRAMP  REM:error amplitude of ICM FStangle signal@*/
extern unsigned_int16_t                        AYC_FYAW_RATE_ERROR_AMPLITUDE;  /*@ LSB:0.00286  UNIT:deg/s NAME:ICMFYAWRATEERRAMP  REM:error amplitude of ICM filtered yaw rate signal@*/
#endif

extern signed_int16_t                          AYC_FILTERED_YAW_RATE;          /*@ LSB:0.00286 UNIT:deg/s  NAME:AFYAWRATE     REM:ayc filtered yaw rate @*/
extern signed_int16_t                          AYC_FILTERED_YAW_RATE_ADJ_CORR; /*@ LSB:0.00286 UNIT:deg/s  NAME:AFYAWRATE_Adj REM:ayc filtered yaw rate adjust correction @*/
extern signed_int16_t                          AYC_FILTERED_YAW_ACCELERATION;  /*@ LSB:0.01146 UNIT:deg/ss NAME:AFYAWACC      REM:ayc filtered yaw acc @*/

#if (AYC_SESP || (CFG_VEHICLE_ID_CHASSIS == cAUDI_TT3) )
extern signed_int16_t                          AYC_FILTERED_YAW_RATE_OLD;      /*@ LSB:0.00286 UNIT:deg/s  NAME:AFYAWRATE_OLD  REM:ayc filtered yaw rate last loop @*/
#endif

#if (CFG_4WS)
extern signed_int16_t                          AYC_FILTERED_REAR_ANGLE;        /*@ LSB:1.526e-3 UNIT:deg   NAME:RWSTANGLE  REM:ayc filtered rear steer angle @*/
extern signed_int16_t                          AYC_FILTERED_REAR_ANGLE_RATE;   /*@ LSB:0.04375 UNIT:deg/s  NAME:RWSTANGLEP REM:ayc filtered rear steer angle rate @*/

extern signed_int16_t                          AYC_DRV_REQ_REAR_ANGLE;         /*@ LSB:1.526e-3 UNIT:deg   NAME:RWDRVREQ   REM:driver requested rear steer angle @*/
extern signed_int16_t                          AYC_DRV_REQ_REAR_ANGLE_RATE;    /*@ LSB:0.04375 UNIT:deg/s  NAME:RWDRVREQP  REM:driver requested rear steer angle rate @*/
#endif

extern signed_int16_t                          AYC_FILTERED_STEER_ANGLE_SUM;   /*@ LSB:1.526e-3 UNIT:deg   NAME:SUMFSTANGLE  REM:sum of filtered steer angle at front and rear axle @*/                    /* --> 17907:1KO20022006 */
extern signed_int16_t                          AYC_DRV_REQ_STEER_ANGLE_SUM;    /*@ LSB:1.526e-3 UNIT:deg   NAME:SUMFSWADRV   REM:sum of driver requested steer angle at front and rear axle @*/            /* <-- 17907:1KO20022006 */

extern unsigned_int16_t                        AYC_FIL_TCS_GEAR_FACTOR;       /*@ LSB:0.1 UNIT: NAME:TCSGEARFAC   REM: filtered Gear-Factor f(N_mot/V_rad) convert the Engine-Torque to Wheel-Torque @*/
extern signed_int16_t                          AYC_FIL_TCS_GEAR_FACTOR_QF;    /*@ LSB:1   UNIT: NAME:TCSGEARFACQF REM: Qualifier which indicates the validity of AYC_FILTERED_GEAR_FACTOR @*/

/* <<< .!A001rl070302. */
extern signed_int16_t                          AYC_WHEEL_PRESSURE[Num_of_wheels];     /*@ LSB:0.01    UNIT:bar    NAME:AYCWHP_%w  REM:actual wheel pressure %w @*/

/******************************************************************************
* 'M A K R O - D E C L A R A T I O N S'                                      *
******************************************************************************/

#define Get_yr_reached_max_value()       (AYC_SENSOR_STATE_BITS.YR_REACHED_MAX_VALUE)    /* 13751:2herrmann17022005 */
#define Set_yr_reached_max_value(x)      (AYC_SENSOR_STATE_BITS.YR_REACHED_MAX_VALUE = (x))

#define Get_yr_confidence_level()        (AYC_SENSOR_STATE_BITS.YR_CONFIDENCE_LEVEL)
#define Set_yr_confidence_level(x)       (AYC_SENSOR_STATE_BITS.YR_CONFIDENCE_LEVEL = (x))

#define Get_sa_confidence_level()        (AYC_SENSOR_STATE_BITS.SA_CONFIDENCE_LEVEL)
#define Set_sa_confidence_level(x)       (AYC_SENSOR_STATE_BITS.SA_CONFIDENCE_LEVEL = (x))

#define Get_latacc_signal_disturbed()    (AYC_SENSOR_STATE_BITS.LAT_ACC_SIGNAL_DISTURBED)
#define Set_latacc_signal_disturbed(x)   (AYC_SENSOR_STATE_BITS.LAT_ACC_SIGNAL_DISTURBED = (x))

/******************************************************************************
* 'F U N C T I O N - P R O T O T Y P E S'                                    *
******************************************************************************/

extern void AYC_INIT_SIGNALS(void);
extern void AYC_INIT_GET_EXTERNAL_SIGNALS(void);
extern void AYC_INIT_SET_VALUES(void);
extern void AYC_INIT_AFTER_SYSTEM_RESET(void);
#if (CFG_AFS)
extern void AYC_CALC_DRV_REQ_STEER_ANGLE(const unsigned_char_t *vari_steer_angle_qf_old,
                                         const unsigned_char_t *vari_steer_angle_qf,
                                         const signed_int16_t  *vari_steer_angle);
#endif

#endif

