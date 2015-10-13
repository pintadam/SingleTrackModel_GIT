/**************************************************************************************************
COPYRIGHT CONTINENTAL TEVES & AG & Co. oHG 1991-20xx
CONFIDENTIAL AND PROPRIETARY. ALL RIGHTS RESERVED - PROPRIETARY OF CONTINENTAL TEVES AG & Co. oHG
ABS/EBD/TCS/ESP-Controller Software
***************************************************************************************************
Filename:            AYC_INIT.H
Analyse-Chart:
Name Functionmodell: AYC
***************************************************************************************************
$Log: AYC_INIT.H  $
Revision 1.47.3.1.1.4 2013/01/15 17:32:11CET Escudero, Paula (Paula)
introduce new feature CFG_AYC_FREQ_STEER_MANEUVER
Revision 1.47.3.1.1.3 2012/02/09 12:44:34CET Meister, Oliver (TFCECS)
Audi TT changed prio for yaw_ref_old
Revision 1.47.3.1.1.2 2011/12/22 15:02:22CET Meister, Oliver (tfcecs)
merged audi features VA9BAC-VA9BA
Revision 1.47.3.1.1.1 2011/08/03 09:41:16CEST Meister, Oliver (TFCECS)
integral controller part for DPSIP for Audi TT3 after resync with MQB partlist F07/4
Revision 1.47.3.1 2011/06/27 15:51:44CEST Weber Jens (WeberJ1) (WeberJ1)
Reorganize Measurement Data Output
Revision 1.47 2009/07/08 12:06:00CEST Nagarajan, Senthilnathan (sentna59)
Replaced Num_of_wheels_ram by Num_of_wheels and included header file sal_wheeltyp.he
Revision 1.46 2009/06/02 14:20:52CEST Nagarajan, Senthilnathan (sentna59)
MISRA 2004 indentation warning resolved, For Rule 2200-2215
Revision 1.45 2009/05/28 09:21:43CEST Ravi, Bhuvanahalli Ramachandra (RaviR)
Include path updated for Layer interface
Revision 1.44 2009/04/23 08:31:11CEST Radowitz, Mirko (RadowitzM)
Remove AYC_SCL_CFG strap
Revision 1.43 2008/08/18 12:43:08CEST Lamm, Holger (lamm)
ICM changes: Error amplitude now unsigned
Revision 1.42 2008/06/10 11:17:26CEST Hartmann, Frank (hartmannf)
Add confidence level for steer angle (SA_CONFIDENCE_LEVEL).
Revision 1.41 2008/06/06 19:27:18CEST Hartmann, Frank (hartmannf)
Add error amplitudes from ICM plausibilities
Revision 1.40 2008/03/03 15:38:48CET Lamm, Holger (lamm)
Fix QAC warnings: Explicit unsigned constants
Revision 1.39 2007/11/15 15:30:51CET simon
- new interface: wheel pressure from CSI signal_box
Revision 1.38 2007/08/01 17:08:08CEST simon
- change ASAP name: FLATACC --> FLATACC_CUR
Revision 1.37 2007/07/04 15:53:15CEST wickenhoefer
- Change interface GET_AYC_VEHICLE_PARAMETER() (34229:3TW040707).
Revision 1.35 2007/05/08 09:35:22CEST wickenhoefer
- Consider disturbed lateral acceleration signal (31843:1TW080507).
Revision 1.34 2006/10/10 13:17:32CEST schulzec
removed QAC warnings
Revision 1.33 2006/10/06 09:20:40CEST schulzec
changed function prototype for AYC_INIT_GET_EXTERNAL_SIGNALS()
Revision 1.32 2006/10/05 17:57:59CEST schulzec
merge changes for 4WS
Revision 1.31 2006/09/22 13:55:01CEST wickenhoefer
- Revise component AYC Init (25695:1TW220906)
Revision 1.30 2006/09/21 16:48:00CEST wickenhoefer
- Delete PDO data output of variant coding (PDO_CFG & 0x40000)
(25717:1TW210906)
Revision 1.29 2006/09/20 18:56:11CEST wickenhoefer
- Add the new confidence factor for yaw rate sensor (25537:1TW200906).
Revision 1.28 2006/07/14 15:24:08CEST weyhmueller
Added the TCS Gear Factor Signal
Revision 1.27 2006/06/01 17:05:35CEST wickenhoefer
- Changes concerning QA-C ruleset Next (13613:49TW010606).
Revision 1.26 2005/11/25 10:57:47CET hartmannf
Create seperate function 'AYC_INIT_VALUES' for values that have to be initialized in COA state 'INIT'.
Revision 1.25 2005/09/09 19:14:43CEST bouzid
corrected paranethtes
Revision 1.24 2005/08/16 13:35:33CEST wickenhoefer
- Categorised AYC-RAM, set extern for all sensor variables (15967:3TW160805).
Revision 1.23 2005/07/28 08:54:05CEST wickenhoefer
- Categorised AYC-RAM, required by RAMDUMP measurement (15967:3TW280705).
Revision 1.22 2005/07/27 18:09:27CEST wickenhoefer
- Categorised AYC-RAM, required by RAMDUMP measurement (15967:3TW270705).
Revision 1.21 2005/07/26 16:04:19CEST weyhmueller
- Modified the RAM classification (Part-II), required for RAMDUMP measurement (15967:FOW).
Revision 1.20 2005/07/21 11:30:12CEST wickenhoefer
- Add new AYC-RAM classification (Part-I), required by RAMDUMP measurement (15967:3TW210705).
Revision 1.19 2005/07/19 14:43:43CEST pank
- added data description for AYC_FILTERED_YAW_RATE_OLD
Revision 1.18 2005/07/19 14:35:34CEST pank
- AYC_FILTERED_YAW_RATE_OLD is also used for AYC_SESP
Revision 1.17 2005/04/25 14:53:14CEST wickenhoefer
Move PDOs for variant coding from ifc_pdo.c to ayc_init.c (10082:29TW250405).
Revision 1.16 2005/04/05 17:27:26CEST baueru
merge for 4WS
Revision 1.15 2005/03/02 11:42:29CET wickenhoefer
Add AYC_FILTERED_YAW_RATE_OLD for AYC_SCL_CFG (5149:10TW030305)
Revision 1.14 2005/02/17 18:39:09CET herrmann
Defintion and setting of Ge/Set_yr_reached_max_value
Revision 1.13 2004/09/15 14:55:38CEST gaertner
Rework sensor disable check.
Revision 1.12 2004/08/23 13:32:46CEST reith
remove varcoding defines
Revision 1.11 2004/07/26 17:22:03CEST reith
Add PDOVAR variables in file ayc_init.c and ayc_init.h for verification of release branches.
Revision 1.10 2004/07/05 16:23:35CEST baueru
correction of comment for AYC_DRV_REQ_STEER_ANGLE_RATE
Revision 1.9 2003/07/21 09:36:44CEST baueru
general introduction of AYC_DRV_REQ_STEER_ANGLE and AYC_DRV_REQ_STEER_ANGLE_RATE
to differentiate in AYC between the driver's requested steering angle and the wheel steering angle
Revision 1.8 2003/07/18 17:21:04CEST baueru
Differentiate between the sum-steering rate (AYC_FILTERED_STEER_ANGLE_RATE) and the
driver requested steering rate (AYC_DRV_REQ_STEER_ANGLE_RATE)
Revision 1.7 2003/03/28 16:34:13CET klaassen
Add PDOVAR data for VAR_CODE
Revision 1.6 2003/02/25 10:37:00CET baueru
Merge of AFS changes to mainstream (Strap CFG_AFS)
Revision 1.5.1.3 2003/02/25 10:20:00CET baueru
To use AFS functionality without GMK straps changed from CFG_GMK to CFG_AFS
Revision 1.5.1.2 2003/01/10 15:58:13CET baueru
getting driver steering angle request (AYC_DRV_REQ_STEER_ANGLE) from AFS as
input for single track model
Revision 1.5.1.2 2003/01/10 15:58:13CET baueru
getting driver steering angle request (AYC_DRV_REQ_STEER_ANGLE) from AFS as
input for single track model
Revision 1.5.1.1 2002/11/19 17:54:08CET baueru
Duplicate revision
Revision 1.5 2002/11/19 17:54:08CET konanz
CUR_LATERAL_ACCELERATION replaced by AYC_CUR_LATERAL_ACCELERATION (#a001KO191102)
Revision 1.4 2002/11/08 17:30:04CET laetitia
001LC120902: Check if SC- or/and SA-sensor defective in order to manage some AYC calculations
Revision 1.3 2002/09/18 18:04:39CEST wickenhoefer
Add ram declerations for AYC_INIT.
Revision 1.2 2002/06/21 12:35:08CEST kuemmel
Insert keyword Log at top of every AYC file
create          08.03.2002   7:43:47 WS718_LEHMER
***************************************************************************************************
*/


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

