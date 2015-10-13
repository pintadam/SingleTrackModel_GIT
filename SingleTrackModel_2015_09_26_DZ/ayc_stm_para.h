

#ifndef ayc_stm_para_h_included
#define ayc_stm_para_h_included
#include "ayc_yref.h"

/* TYP definitions */
#include "hal_base_type_if.he"

/******************************************************************************
 * 'I N T E G E R - V A R I A B L E S  -  V E R I F I C A T I O N  ( A Y C )' *
 ******************************************************************************/

#if (PDO_CFG & 0x80000)
/******************************************************************************
 *                       'I N P U T - V A L U E S '                           *
 ******************************************************************************/
 extern signed_int16_t PDOVAR_STM_COD_C_F;                        /*@ LSB:        UNIT:       NAME:COD_C_F        REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_C_R;                        /*@ LSB:        UNIT:       NAME:COD_C_R        REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_L_F;                        /*@ LSB:        UNIT:       NAME:COD_L_F        REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_L_R;                        /*@ LSB:        UNIT:       NAME:COD_L_R        REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_H_COG;                      /*@ LSB:        UNIT:       NAME:COD_H_COG      REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_MASS;                       /*@ LSB:        UNIT:       NAME:COD_MASS       REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_THETA;                      /*@ LSB:        UNIT:       NAME:COD_THETA      REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_TRACK_FA;                   /*@ LSB:        UNIT:       NAME:COD_TRACK_FA   REM:     @*/
 extern signed_int16_t PDOVAR_STM_COD_TRACK_RA;                   /*@ LSB:        UNIT:       NAME:COD_TRACK_RA   REM:     @*/
 extern signed_int16_t PDOVAR_STM_MAX_DFFLAT_Y_0;                 /*@ LSB:        UNIT:       NAME:MAX_DFFLAT_Y_0 REM:     @*/
 extern signed_int16_t PDOVAR_STM_MAX_DFFLAT_Y_1;                 /*@ LSB:        UNIT:       NAME:MAX_DFFLAT_Y_1 REM:     @*/
#endif /*PDO Definition*/

/******************************************************************************
 * 'I N T E G E R - V A R I A B L E S  ( A Y C )'                             *
 ******************************************************************************/
 extern signed_int16_t ESM_C2_PSIPP;                      /*@ LSB:        UNIT:      NAME:ESM_C2_PSIPP                REM:    @*/
 extern signed_int16_t ESM_C1_ALPHAFLIM;                  /*@ LSB:        UNIT:      NAME:ESM_C1_ALPHAFLIM            REM:    @*/
 extern signed_int16_t ESM_C1_FFLATKORR;                  /*@ LSB:        UNIT:      NAME:ESM_C1_FFLATKORR            REM:    @*/
 extern signed_int16_t ESM_C1_BETAP;                      /*@ LSB:        UNIT:      NAME:ESM_C1_BETAP                REM:    @*/
 extern signed_int16_t ESM_C1_BETASET;                    /*@ LSB:        UNIT:      NAME:ESM_C1_BETASET              REM:    @*/
 extern signed_int16_t ESM_C1_FFLAT;                      /*@ LSB:        UNIT:      NAME:ESM_C1_FFLAT                REM:    @*/
 extern signed_int16_t ESM_C1_FFLATLIM;                   /*@ LSB:        UNIT:      NAME:ESM_C1_FFLATLIM             REM:    @*/
 extern signed_int16_t ESM_C1_FRLAT;                      /*@ LSB:        UNIT:      NAME:ESM_C1_FRLAT                REM:    @*/
 extern signed_int16_t ESM_C1_PSIPP;                      /*@ LSB:        UNIT:      NAME:ESM_C1_PSIPP                REM:    @*/
 extern signed_int16_t ESM_C2_BETAP;                      /*@ LSB:        UNIT:      NAME:ESM_C2_BETAP                REM:    @*/
 extern signed_int16_t ESM_C2_BETASET;                    /*@ LSB:        UNIT:      NAME:ESM_C2_BETASET              REM:    @*/
 extern signed_int16_t ESM_C1_ALPHAF;                     /*@ LSB:        UNIT:      NAME:ESM_C1_ALPHAF               REM:    @*/
 extern signed_int16_t ESM_C1_ALPHAR;                     /*@ LSB:        UNIT:      NAME:ESM_C1_ALPHAR               REM:    @*/
 extern signed_int16_t ESM_C1_PSIPSET;                    /*@ LSB:        UNIT:      NAME:ESM_C1_PSIPSET              REM:    @*/
 extern signed_int16_t ESM_C3_BETASET;                    /*@ LSB:        UNIT:      NAME:ESM_C3_BETASET              REM:    @*/
 extern signed_int16_t MODPR_SCALED_EG;                   /*@ LSB:        UNIT:      NAME:MODPR_SCALED_EG             REM:    @*/
 extern signed_int16_t MODPR_SCALED_WHEELBASE;            /*@ LSB:        UNIT:      NAME:MODPR_SCALED_WHEELBASE      REM:    @*/
 extern signed_int16_t VS_DV_TH_FA;                       /*@ LSB:        UNIT:      NAME:VS_DV_TH_FA                 REM:    @*/
 extern signed_int16_t VS_DV_TH_RA;                       /*@ LSB:        UNIT:      NAME:VS_DV_TH_RA                 REM:    @*/
 extern signed_int16_t VS_PSIP_CORR_FA;                   /*@ LSB:        UNIT:      NAME:VS_PSIP_CORR_FA             REM:    @*/
 extern signed_int16_t VS_PSIP_CORR_RA;                   /*@ LSB:        UNIT:      NAME:VS_PSIP_CORR_RA             REM:    @*/
 extern signed_int16_t VS_PSIP_N_FA;                      /*@ LSB:        UNIT:      NAME:VS_PSIP_N_FA                REM:    @*/
 extern signed_int16_t VS_PSIP_N_RA;                      /*@ LSB:        UNIT:      NAME:VS_PSIP_N_RA                REM:    @*/
 extern signed_int16_t VS_SCALED_TRACK_FA;                /*@ LSB:        UNIT:      NAME:VS_SCALED_TRACK_FA          REM:    @*/
 extern signed_int16_t VS_SCALED_TRACK_RA;                /*@ LSB:        UNIT:      NAME:VS_SCALED_TRACK_RA          REM:    @*/
 extern signed_int16_t VREF_TRACK_WIDTH;                  /*@ LSB:        UNIT:      NAME:VREF_TRACK_WIDTH            REM:    @*/
 extern signed_int16_t DPSIP_LAT_GRAD_CORR_FAC2;          /*@ LSB:        UNIT:      NAME:DPSIP_LAT_GRAD_CORR_FAC2    REM:    @*/
 extern signed_int16_t ADAPT_C_R_DENUM_1;                 /*@ LSB:        UNIT:      NAME:ADAPT_C_R_DENUM_1           REM:    @*/
 extern signed_int16_t ADAPT_C_R_NUM;                     /*@ LSB:        UNIT:      NAME:ADAPT_C_R_NUM               REM:    @*/
 extern signed_int16_t ADAPT_C_R_DENUM_3;                 /*@ LSB:        UNIT:      NAME:ADAPT_C_R_DENUM_3           REM:    @*/
 extern signed_int16_t ADAPT_C_R_DENUM_4;                 /*@ LSB:        UNIT:      NAME:ADAPT_C_R_DENUM_4           REM:    @*/
 extern signed_int16_t ADAPT_C_R_NUM_1;                   /*@ LSB:        UNIT:      NAME:ADAPT_C_R_NUM_1             REM:    @*/
 extern signed_int16_t ESM_MAX_DELTA_FFLAT_Y_MS[2];       /*@ LSB:        UNIT:      NAME:ESM_MAX_DELTA_FFLAT_Y_MS    REM:    @*/
 extern signed_int16_t ESM_LAT_FORCE_DELAY_VEL_TAB[4];    /*@ LSB:        UNIT:      NAME:ESM_LAT_FORCE_DELAY_VEL     REM:    @*/
 extern signed_int16_t ESM_LAT_FORCE_DELAY_FCONST_TAB[4]; /*@ LSB:        UNIT:      NAME:ESM_LAT_FORCE_DELAY_FCONST  REM:    @*/

/* --- 'I N T E G E R' variables for codable bike model (CSI) ---- */
 extern signed_int16_t YAW_STEER_SCALE_1;                 /*@ LSB:        UNIT:      NAME:YAW_STEER_SCALE_1         REM:    @*/
 extern signed_int16_t YAW_STEER_SCALE_2;                 /*@ LSB:        UNIT:      NAME:YAW_STEER_SCALE_2         REM:    @*/
 extern signed_int16_t L_ACC_COG;                         /*@ LSB:        UNIT:      NAME:L_ACC_COG                 REM:    @*/
 extern signed_int16_t L_ACC_DELTA_Y;                     /*@ LSB:        UNIT:      NAME:L_ACC_DELTA_Y             REM:    @*/
 extern signed_int16_t L_ACC_FA;                          /*@ LSB:        UNIT:      NAME:L_ACC_FA                  REM:    @*/
 extern signed_int16_t L_ACC_RA;                          /*@ LSB:        UNIT:      NAME:L_ACC_RA                  REM:    @*/
 extern signed_int16_t SP_TRACK_SCALE;                    /*@ LSB:        UNIT:      NAME:SP_TRACK_SCALE            REM:    @*/

/* ------------------------- Find Center ------------------------- */
#if CFG_SWA_FIND_CENTER_MODULE==2
 extern signed_int16_t FC_VEHICLE_US_COEFFICIENT;         /*@ LSB:        UNIT:      NAME:FC_VEH_US_COEF            REM:    @*/
 extern signed_int16_t FC_VEHICLE_WHEEL_BASE;             /*@ LSB:        UNIT:      NAME:FC_VEH_WH_BASE            REM:    @*/
#endif

/* --- 'I N T E G E R' variables for codable bike model (FSF) ---- */
 extern signed_int16_t FSF_PL_STEEP_MODEL_CONST1;         /*@ LSB:        UNIT:      NAME:FSF_PL_STEEP_MODEL_CONST1 REM:   @*/
 extern signed_int16_t FSF_PL_STEEP_MODEL_CONST2;         /*@ LSB:        UNIT:      NAME:FSF_PL_STEEP_MODEL_CONST2 REM:   @*/

/***********************************************************************************************/
/*                                Scaling Factors and Resolutions                              */
/***********************************************************************************************/

#define COD_c_lsb         16         /* [N/rad/bit] */
#define COD_scale         1024       /* [1/(m/bit)] */
#define COD_l_lsb_r      (COD_scale)
#define COD_h_cog_lsb_r  (COD_scale)
#define COD_track_lsb_r  (COD_scale)
#define Cod_stm_max_delta_fflat_x 0

/***********************************************************************************************/
/*                                     Defines not driven axle                                 */
/***********************************************************************************************/

#if (REAR_DRIVEN_CFG)
  #define Track_not_drv         Ayc_esm_track_fa
#else
  #define Track_not_drv         Ayc_esm_track_ra
#endif

/***********************************************************************************************/
/*                                     Defines for ROM/EEPROM-Version                                 */
/***********************************************************************************************/


#define COD_c_f                    Ayc_esm_c_f                     /*LSB =     16 N/rad */
#define COD_c_r                    Ayc_esm_c_r                     /*LSB =     16 N/rad */
#define COD_l_f                    Ayc_esm_l_f                     /*LSB = 1/1024 m     */
#define COD_l_r                    Ayc_esm_l_r                     /*LSB = 1/1024 m     */
#define COD_h_cog                  Ayc_esm_h_cog                   /*LSB = 1/1024 m     */
#define COD_mass                   Ayc_esm_m                       /*LSB =      1 kg    */
#define COD_theta                  Ayc_esm_theta                   /*LSB =      1 kg*m^2*/
#define COD_track_fa               Ayc_esm_track_fa                /*LSB = 1/1024 m     */
#define COD_track_ra               Ayc_esm_track_ra                /*LSB = 1/1024 m     */
#define Esm_max_delta_fflat_x      Cod_stm_max_delta_fflat_x       /*LSB =  1/100       */
#define Ayc_esm_max_delta_fflat_y  Cod_stm_max_delta_fflat_y       /*LSB =  1/100       */
#define COD_lat_force_delay_vel_tab_val1    Ayc_lat_force_delay_vel_tab[0]    /*LSB = 1/100  kph   */
#define COD_lat_force_delay_vel_tab_val2    Ayc_lat_force_delay_vel_tab[1]    /*LSB = 1/100  kph   */
#define COD_lat_force_delay_vel_tab_val3    Ayc_lat_force_delay_vel_tab[2]    /*LSB = 1/100  kph   */
#define COD_lat_force_delay_vel_tab_val4    Ayc_lat_force_delay_vel_tab[3]    /*LSB = 1/100  kph   */
#define COD_lat_force_delay_fconst_tab_val1 Ayc_lat_force_delay_fconst_tab[0] /*LSB = 1/1          */
#define COD_lat_force_delay_fconst_tab_val2 Ayc_lat_force_delay_fconst_tab[1] /*LSB = 1/1          */
#define COD_lat_force_delay_fconst_tab_val3 Ayc_lat_force_delay_fconst_tab[2] /*LSB = 1/1          */
#define COD_lat_force_delay_fconst_tab_val4 Ayc_lat_force_delay_fconst_tab[3] /*LSB = 1/1          */
#define Esm_c1_fflatlim_corr_fac            Ayc_esm_c1_fflatlim_corr_fac      /*LSB = 1/100        */


#if (AYC_COD_ESM == 2 && CFG_CUSTOMER == cCFG_BMW)  /*EEPROM-Version BMW*/
/* Vehicle_index == 1      ==>     EEPROM-Values*/
#define COD_c_f                    ((Vehicle_index == 1) ? Stm_eep_c_f                                                     : Ayc_esm_c_f      )   /*LSB =     16 N/rad */
#define COD_c_r                    ((Vehicle_index == 1) ? Stm_eep_c_r                                                     : Ayc_esm_c_r      )   /*LSB =     16 N/rad */
#define COD_l_f                    ((Vehicle_index == 1) ? INTLIM(((signed_int32_t)Stm_eep_l_f*1024)/50)                   : Ayc_esm_l_f      )   /*LSB = 1/1024 m     */
#define COD_l_r                    ((Vehicle_index == 1) ? INTLIM(((signed_int32_t)Stm_eep_l_r*1024)/50)                   : Ayc_esm_l_r      )   /*LSB = 1/1024 m     */
#define COD_h_cog                  (Ayc_esm_h_cog)                                                                                                /*LSB = 1/1024 m     */
#define COD_mass                   ((Vehicle_index == 1) ? INTLIM(Stm_eep_mass*20)                                         : Ayc_esm_m        )   /*LSB =      1 kg    */
#define COD_theta                  ((Vehicle_index == 1) ? INTLIM(Stm_eep_theta*20)                                        : Ayc_esm_theta    )   /*LSB =      1 kg*m^2*/
#define COD_track_fa               ((Vehicle_index == 1) ?INTLIM(((signed_int32_t)(Stm_eep_track+70)*1024)/50)             : Ayc_esm_track_fa )   /*LSB = 1/1024 m     */
#define COD_track_ra               ((Vehicle_index == 1) ?INTLIM(((signed_int32_t)(Stm_eep_track+70)*1024)/50)             : Ayc_esm_track_ra )   /*LSB = 1/1024 m     */
#define Esm_max_delta_fflat_x      (Cod_stm_max_delta_fflat_x)                                                                                    /*LSB =  1/100       */
#define Ayc_esm_max_delta_fflat_y  (Cod_stm_max_delta_fflat_y)                                                                                    /*LSB =  1/100       */
#endif /*End of EEPROM-Version BMW*/

#define Esm_c2_psipp               ESM_C2_PSIPP
#define Esm_c1_alphaflim           ESM_C1_ALPHAFLIM
#define Esm_c1_fflatkorr           ESM_C1_FFLATKORR
#define Esm_c1_betap               ESM_C1_BETAP
#define Esm_c1_betaset             ESM_C1_BETASET
#define Esm_c1_fflat               ESM_C1_FFLAT
#define Esm_c1_fflatlim            ESM_C1_FFLATLIM
#define Esm_c1_frlat               ESM_C1_FRLAT
#define Esm_c1_psipp               ESM_C1_PSIPP
#define Esm_c2_betap               ESM_C2_BETAP
#define Esm_c2_betaset             ESM_C2_BETASET
#define Esm_c1_alphaf              ESM_C1_ALPHAF
#define Esm_c1_alphar              ESM_C1_ALPHAR
#define Esm_c1_psipset             ESM_C1_PSIPSET
#define Esm_c3_betaset             ESM_C3_BETASET
#define Modpr_scaled_eg            MODPR_SCALED_EG
#define Modpr_scaled_wheelbase     MODPR_SCALED_WHEELBASE
#define Vs_dv_th_fa                VS_DV_TH_FA
#define Vs_dv_th_ra                VS_DV_TH_RA
#define Vs_psip_corr_fa            VS_PSIP_CORR_FA
#define Vs_psip_corr_ra            VS_PSIP_CORR_RA
#define Vs_psip_n_fa               VS_PSIP_N_FA
#define Vs_psip_n_ra               VS_PSIP_N_RA
#define Vs_scaled_track_fa         VS_SCALED_TRACK_FA
#define Vs_scaled_track_ra         VS_SCALED_TRACK_RA
#define Vref_track_width           VREF_TRACK_WIDTH
#define Dpsip_lat_grad_corr_fac2   DPSIP_LAT_GRAD_CORR_FAC2
#define Adapt_c_r_denum_1          ADAPT_C_R_DENUM_1
#define Adapt_c_r_num              ADAPT_C_R_NUM
#define Adapt_c_r_denum_3          ADAPT_C_R_DENUM_3
#define Adapt_c_r_denum_4          ADAPT_C_R_DENUM_4
#define Adapt_c_r_num_1            ADAPT_C_R_NUM_1
#define Esm_max_delta_fflat_y_ms   ESM_MAX_DELTA_FFLAT_Y_MS
#define Esm_lat_force_delay_vel_tab    ESM_LAT_FORCE_DELAY_VEL_TAB
#define Esm_lat_force_delay_fconst_tab ESM_LAT_FORCE_DELAY_FCONST_TAB

/* ---- Defines for ROM-Version for codable bike model (CSI) ----- */
#define Yaw_steer_scale_1          YAW_STEER_SCALE_1
#define Yaw_steer_scale_2          YAW_STEER_SCALE_2
#define L_acc_cog                  L_ACC_COG
#define L_acc_delta_y              L_ACC_DELTA_Y
#define L_acc_fa                   L_ACC_FA
#define L_acc_ra                   L_ACC_RA
#define Sp_track_scale             SP_TRACK_SCALE

/* ------------------------- Find Center ------------------------- */
#if CFG_SWA_FIND_CENTER_MODULE == 2
  #define Fc_vehicle_us_coefficient FC_VEHICLE_US_COEFFICIENT
  #define Fc_vehicle_wheel_base     FC_VEHICLE_WHEEL_BASE
#endif

/* ---- Defines for ROM-Version for codable bike model (FSF) ----- */
#define Fsf_pl_steep_model_const1   FSF_PL_STEEP_MODEL_CONST1
#define Fsf_pl_steep_model_const2   FSF_PL_STEEP_MODEL_CONST2

void CALC_STM_PARA (void);

#endif



