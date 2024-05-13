/*************************************************************************
*
* File name   	: vars_legacy.c
* Description 	: A description of the module's purpose
*
* Copyright: (c) 2017 Technosoft S.A.
*************************************************************************/
/* C libraries include section */
#include <stdint.h>
#include <stdbool.h>

/* Global header include section */
#include "../INCLUDE/global_def.h"

/* Driver headers include section */
#include "_DRIVERS/_common_drv_data_types.h"
#include "_DRIVERS/cpu_drv.h"
#include "_DRIVERS/biss_drv.h"
#include "_DRIVERS/aformat_drv.h"
#include "_DRIVERS/ethercat_drv.h"

/* Firmware modules include section */
#include "COMM/comm.h"
#include "COMM/CANOPEN/canopen.h"
#include "TML/tml.h"
#include "vars_legacy.h"
#include "vars.h"

/*************************************************************************
* Global variables
*************************************************************************/
/* variable used to fill unused entries in the pointers tables */
uint16_t null_padding_variable;
uint16_t cmpa;
uint16_t cmpb;
uint16_t cmpc;
uint16_t cmpd;
uint16_t cvdc_table_index;
boolean_t faulty_current_measurements;
uint16_t currents_acquisition_index;

/* Page 200 parameters and variables */
uint16_t number_of_drive_inputs;
uint16_t volatile asr;						/* [ASR] AUXILIARY SETTINGS REGISTER */
int16_t fast_loop_counter;
int16_t slow_loop_counter;
int16_t number_of_drive_outputs;
int16_t tmp_slow[4];
int16_t tmp_fast[4];
int16_t new_actr_value_or_time_0;
int16_t cmpr_plus_or_thetainc_im;
int16_t cmpr_minus_or_thetalow_im;
int32_t volatile fdbk1_new_position;
int32_t volatile fdbk1_old_position;
uint16_t fdbk1_missing_threshold;
uint16_t fdbk2_missing_threshold;
int16_t pos_2theta_1;
int16_t hall_1;
int16_t pos_err_1;
int16_t sat_out_spd_1;
int16_t pos_inc;
int16_t electric_position;
uint32_t pos_2theta;
int16_t load;
int16_t theta;
int16_t sin_theta;
int16_t cos_theta;
int16_t volatile hall;
int32_t volatile apos_load;
int32_t volatile apos_load_1;
int16_t pos_err;
int16_t spd_ref;
int32_t volatile motor_speed;
int32_t volatile can_motor_speed;
int16_t spd_err;
int16_t i_q_ref;
int16_t i_q;
int16_t crt_err;
int16_t u_q_ref;
int16_t i_d_ref;
int16_t i_d;
int16_t u_d_ref;
int16_t u_a_ref;
int16_t u_b_ref;
int16_t u_c_ref;
int16_t volatile current_ia_os;
int16_t volatile current_ib_os;
int16_t volatile current_ic_os;
int16_t volatile current_ia_low_scale_os;
int16_t volatile current_ib_low_scale_os;
int16_t volatile current_ic_low_scale_os;
int16_t volatile current_ic_low_scale_os_2;
int16_t volatile current_ic_low_scale_os_3;
int16_t volatile current_ia;
int16_t volatile current_ib;
int16_t volatile current_ic;
int16_t volatile current_id;
int16_t volatile current_ia_low_scale;
int16_t volatile current_ib_low_scale;
int16_t volatile current_ic_low_scale;
int16_t volatile current_id_low_scale;
int16_t volatile current_ia_raw;
int16_t volatile current_ib_raw;
int16_t volatile current_ic_raw;
int16_t volatile current_id_raw;
int16_t volatile current_ia_low_scale_raw;
int16_t volatile current_ib_low_scale_raw;
int16_t volatile current_ic_low_scale_raw;
int16_t volatile current_id_low_scale_raw;
/* Buffer variables for stepper currents*/
int16_t volatile current_ia_st;
int16_t volatile current_ib_st;
int16_t volatile current_ic_st;
int16_t volatile current_id_st;
int16_t stepper_current_ia;
int16_t stepper_current_ib;
uint16_t ad_res_0;
uint16_t ad_res_1;
uint16_t ad_res_2;	// Legacy FDBK
uint16_t ad_res_3;
uint16_t ad_res_4;
uint16_t ad_res_5;	//REF
uint16_t ad_res_6;
uint16_t ad_res_7;
int16_t offset_ad0_v;
int16_t offset_ad1_v;
uint16_t offset_ad2_p;
uint16_t linear_hall_1_offset;
uint16_t offset_ad4_p;
uint16_t offset_ad5_p;
uint16_t offset_ad7_p;
uint16_t linear_hall_2_offset;
int32_t cqep2theta_long;
int32_t nlines_el_rev_long;
int16_t fast_max_counts;
int16_t slow_max_counts;
uint16_t pwm_period;
uint16_t dbt;
int16_t u_sat_pwm;
//uint32_t gear_master;
uint16_t gear_master;
uint16_t gear_slave;
uint16_t phase_adv;
uint16_t linear_hall_3_offset;
int16_t hall_config_or_theta_inc_weak;
uint16_t v_dc_nominal;
int16_t c_v_dc;
int16_t c_analogue_in;
int16_t sh_c_analogue_in;
int16_t kp_pos;
int16_t sh_p_pos;
int16_t ki_pos;
int16_t sh_i_pos;
int16_t kd_pos;
int16_t sh_d_pos;
int16_t kdf_pos;
int16_t sat_out_pos;
int16_t sat_int_pos;
int16_t kp_spd;
int16_t sh_p_spd;
int16_t ki_spd;
int16_t sh_i_spd;
int16_t sat_out_spd;
int16_t sat_int_spd;
int16_t kff_spd;
int16_t kff_acc;
int16_t kff_acc_dec;
int16_t kff_acc_internal;
int16_t kff_load;
int16_t sh_kff;
int16_t kp_crt;
int16_t sh_p_crt;
int16_t ki_crt;
int16_t sh_i_crt;
int16_t sat_out_crtd;
int16_t sat_out_crtq;
int16_t nlines_el_rev_or_c_spd;
int16_t cqep2theta_or_sh_c_spd;
int16_t linear_hall_3_gain;
int16_t homopolar_comp;
int16_t i_d_ref_max;
int16_t i_d_ref_min;
int16_t boost_voltage;
int16_t filter_coeficient;
int16_t linear_hall_interpolation;
int16_t increment_ref_test;
int16_t reference_test;
int16_t theta_test;
int16_t theta_inc_test_or_ho;
uint16_t time_a;
uint16_t time_b;
uint16_t brake_control_register;
int16_t linear_hall_1_gain;
int16_t pos_long_compensation;
int32_t exotic_position_offset;
int32_t exotic_position_offset_long;
uint16_t level_brake_on;
int16_t brake_duty_cycle;
int16_t brake_off_level;
int16_t linear_hall_1_max;
int16_t k_i_q;
int16_t linear_hall_2_gain;
int16_t sft_current;
int16_t sh_t_ai;
int16_t sh_t_si;
int16_t sh_t_ai_dec;
int16_t sh_t_ai_internal;
uint16_t configreg_sync;
int16_t imax;
uint32_t alpha;
uint16_t t1max;
uint16_t t2max;
uint16_t umax;
uint16_t umin;
uint16_t n_max;
int16_t filter_1;
int32_t c_pos;
int32_t c_spd;
int32_t c_acc;
int32_t c_dref;
uint16_t c_time;
uint16_t volatile asr2;			/* [ASR2] AUXILIARY SETTINGS REGISTER 2 */
int32_t c_ref;
int32_t cam_masterpos;
int32_t eg_ratio;
int32_t ref;
uint16_t volatile mcr_1;
uint16_t t_pif;
int32_t t_pi;
int32_t t_si;
int32_t t_ai;
int32_t pos0;
int32_t pos_rel;
int32_t cap_pos;
int32_t ml_time0;
int32_t ml_time;
int32_t ml_rtime;
uint16_t tonimax;
int16_t errprot;
uint16_t tonerr;
uint16_t earth_fault_level;
int32_t c_a;
uint32_t c_1a;
int32_t dref;
int32_t rg_p;
int32_t rg_ss;
int32_t rg_js;
int32_t rg_a;
uint32_t rg_1a;
int32_t rg_s;
uint16_t rg_ti;
uint16_t rg_p0if;
int32_t rg_p0i;
int32_t rg_pdi;
int32_t t_dpi;
int32_t t_si1;
int32_t m_ref1;
uint32_t rg_temp1;
uint32_t rg_temp2;
uint16_t rg_pdif;
uint16_t rg_temp3f;
int32_t rg_temp3;
uint16_t contor_1;		/* XXX: no longer used */
int16_t ref_high;
int16_t sign;
int16_t eg_init;
int32_t spd_ref_long;
int32_t capture_value_32;
uint16_t comm_channel_type;
int16_t flag_t_undflw;
int16_t pos_2theta_filtered;
int16_t pos_2theta_filtered_integral;
int16_t fdbk1_encoder_sense;
int16_t fdbk2_encoder_sense;
int16_t monitor_encoder_sense;
int16_t t_prescaler;
int16_t flag_uv = 0;
int16_t u_offset;
int16_t k_omega;
int16_t linear_hall_1_min;
int16_t linear_hall_2_max;
int16_t u_stbycrt;
uint16_t volatile scr;	/* [SCR] SYSTEM CONFIGURATION REGISTER */
uint16_t volatile cer;	/* [CER] COMMUNICATION ERROR REGISTER */
uint16_t volatile osr;	/* [OSR] OPERATING SETTINGS REGISTER */
uint16_t volatile pcr;	/* [PCR] PROTECTIONS CONTROL REGISTER */
uint16_t volatile icr;	/* [ICR] */
uint16_t volatile der2;	/* [DER2] */
uint16_t volatile pcr_1;
uint16_t volatile isr;	/* [ISR] = INTERRUPT STATUS REGISTER */
uint16_t *p_int_table;	/* Pointer to the interrupt table start address */
uint16_t volatile msr;	/* [MSR] MOTION STATUS REGISTER */
uint16_t volatile mcr;	/* [MCR] MOTION CONTROL REGISTER */
uint16_t volatile ccr;	/* [CCR] COMMUNICATION CONTROL REGISTER */
uint16_t volatile csr;	/* [CSR] COMMUNICATION STATUS REGISTER */
uint16_t volatile aar;	/* [AAR] AXIS ADDRESS REGISTER */
uint16_t volatile cbr;	/* [CBR] CAN BAUDRATE REGISTER */
int16_t ml_p[3];
int16_t gearslave_id;
int16_t motor_on;
uint16_t **pp_ip1_break;	/* Used to save/restore the TML stack pointer */
uint16_t **pp_ip2_break;	/* Flag to indicate a TML function abort */
uint16_t *p_ip;				/* TML instruction pointer */
uint16_t *p_ip_sw;			/* Instruction pointer returned by switcher */
uint16_t *p_ip_prog;		/* Pointer used for IP restoration */
int16_t restore_ip;	/* Flag that the IP must be restored */
uint16_t *p_ip_break;		/*  */
uint16_t **pp_stack_pointer;	/* TML stack pointer */
uint16_t mli_code;	/* Instruction word returned from read_mli function */
int16_t ml_var_page;
uint16_t mli_temp_0;
uint16_t mli_temp_1;
int16_t ml_data[4];
int32_t ml_comp_l;
int32_t ml_event_reg;
int32_t ml_comp_r;
uint16_t ml_event_mask;
uint16_t drive_disabled;
uint16_t mer_mask_1;
int16_t index_value;
uint16_t download_count;
int16_t data_length;	/* Data length information / former named: _Len*/
int16_t timeout;
tml_msg_t *p_ml_kernel_buffer;
tml_msg_t message_buffer[MSG_BUF_LEN];
tml_msg_t tx_message_buffer[TX_MSG_BUF_LEN];
uint16_t data_buffer[3];	/* 3 word data buffer */
uint32_t takedata_timeout;
int16_t n_new_baudrate;
tml_msg_t *p_rx_buffer;
tml_msg_t *p_tx_buffer;
tml_msg_t *p_rx_pointer;
tml_msg_t *p_tx_pointer;
int16_t sci_tmprx;
int16_t sci_tmptx;
tml_msg_t *p_switch_rx_buffer;
int32_t ad_filt;
int32_t ad2_filt;
uint16_t contor_imax;
uint16_t contor_err;
uint16_t contor_2;
uint16_t log_ptr;
int16_t var_i1;
int16_t var_i2;
int32_t var_lf;
uint16_t err_min;
uint16_t ton_err_min;
uint16_t contor_err_min;
uint16_t ml_stack[TML_STACK_SIZE];	/* The TML SOFTWARE PROCESSOR STACK */
int16_t tml_int_time0;
int16_t tml_inactive;	/* Flags if the TML program must stop execution */
tml_msg_t *p_txbuf_rd;
int32_t transmission;
int32_t aspd_mt_temp;
int16_t time_dimension_index;
int16_t time_notation_index;
uint16_t real_tonerr;
uint16_t real_tonerrmin;
uint16_t real_time_jerk;
uint16_t real_spdtonerr;
factor_group_t position_factor;
factor_group_t velocity_factor;
factor_group_t velocity_encoder;
factor_group_t acceleration_factor;
factor_group_t acceleration_scaling;
factor_group_t time_factor;
factor_group_t jerk_factor;
factor_group_t jerk_scaling;
factor_group_t gear_ratio;
factor_group_t feed_constant;
factor_group_position_encoder_t pos_encoder;
uint16_t master_settings;
uint16_t ext_ref_selection;
uint16_t save_config;
uint16_t homing_method;
int32_t real_home_offset;
uint32_t real_low_speed;
uint32_t real_high_speed;
int32_t home_c_acc;
int32_t *p_can_new_msg;
int32_t *p_can_old_msg;
int16_t w_flag_can_buff;
uint16_t volatile der;	/* [DER] DETAILED ERROR REGISTER */
uint16_t cam_ram_add;
int16_t cam_ram_st_add;
uint8_t NMS_b_NodeState;
uint16_t dma_aei_transfer_command;

uint16_t *p_ml_stack[TML_STACK_SIZE];

/* Page 800 parameters and variables */
int16_t linear_hall_1_raw;
int16_t linear_hall_2_raw;
int16_t t_rectangle;
int16_t hall_a_filt;
int16_t hall_b_filt;
int16_t fdbk1_qep_rev_counting;
int16_t kiq_low_speed;
int16_t pos_comp_inc;
int16_t cos_theta_min;
int16_t hall_filter_coef;
int16_t final_angle;
uint16_t ad_res_8;
int16_t spdref_bq_ini;
int16_t iqref_bq_ini;
int16_t aspd_bq_ini;
int32_t electric_pos_long;
int32_t electric_pos_long_th;
uint32_t fdbk2_new_position;
uint32_t fdbk2_old_position;
uint32_t monitor_new_position;
uint32_t monitor_old_position;
int64_t monitor_driver_full_bits_range;
int32_t monitor_speed;
int32_t volatile apos_monitor;
uint32_t i2t_integral_limit;
int32_t i2t_integral;
int32_t ia_i2t_integral;
int32_t ib_i2t_integral;
int32_t ic_i2t_integral;
int16_t i_i2t_prot;
int16_t i_i2t_prot_phase;
int16_t sf_i2t;
int16_t sf_i2t_phase;
int16_t i2t_trigger_cause;
int32_t master_resolution;
int32_t pos2;
int32_t cap_pos2;
int16_t mspd;
int16_t pos2_inc;
uint16_t lss_aar;
uint16_t lss_cbr;
uint16_t lss_active;
int16_t scibr_init;
uint32_t tx_buf_free_index;
int32_t eg_correction;
int32_t sum_eg_corr;
int32_t minc;
int64_t sinc;	/* 48bit ??? */
int16_t quick_stop_status;
int32_t t_pi1;
int16_t ls_active;
uint16_t alpha2;
int32_t apos_rec;
int16_t lsn_state;
int16_t lsp_state;
int32_t tpos_old;
int32_t y_first;
int32_t y_last;
int32_t x1_1;
int16_t cam_flag;
uint16_t ssi_nr_of_params;
uint16_t ssi_type_of_fdbk;
uint16_t fdbk1_bits_st;
uint16_t fdbk1_bits_mt;
uint16_t fdbk2_bits_st;
uint16_t fdbk2_bits_mt;
uint16_t fdbk1_is_gray_coded;
uint16_t fdbk2_is_gray_coded;
uint16_t fdbk1_encoder_baudrate;
uint16_t fdbk2_encoder_baudrate;
uint16_t fdbk1_time_tr_txrx;
uint16_t fdbk1_time_tr_rxtx;
uint16_t fdbk2_time_tr_txrx;
uint16_t fdbk2_time_tr_rxtx;
int16_t offset_pos_delta;
int16_t sin_speed_acq;
int16_t ssi_ccr_ini;
uint32_t step_resolution_long;
int32_t encoder_resolution_long;
int16_t cos_speed_acq;
int16_t u_a_ref_bkp;
int16_t u_b_ref_bkp;
int16_t u_c_ref_bkp;
int16_t linear_hall_3_min;
int16_t linear_hall_3_coeff;
int16_t linear_hall_1_amplitude;
int16_t linear_hall_2_amplitude;
int16_t el_angle_fract;
uint16_t volatile upgrade;	/* [UPGRADE] UPGRADE REGISTER */
int32_t c_dec;
int16_t cntrl_mode;
int16_t write_index;
int16_t read_index;
int16_t free_index;
int16_t first_pvt_point;
int16_t cyclic_interpolation_active;
int32_t pvt_spd_1;
int16_t pvt_intgr_counter;
int16_t pvt_status;
int16_t pvt_buf_st_addr;
uint16_t pvt_buf_len;
uint16_t pvt_buf_rd;
uint16_t pvt_buf_wr;
int16_t pvt_buf_crt_len;
int16_t pvt_setpvt_value;
int32_t pvt_pos0;
int32_t pvt_pos1;
int16_t pvt_n_buf_low;
uint16_t pvt_time_init;
uint16_t level_ad5;
int32_t m_ref2;
int32_t m_ref_1;
uint32_t elpos_long;
uint16_t e_level_ad5;
int16_t delta_el_pos;
int16_t registration_active;
int16_t spd_err_prot;
uint16_t spd_ton_err;
int16_t i_beta;
int16_t i2_filtered;
int16_t ia2_filtered;
int16_t ib2_filtered;
int16_t ic2_filtered;
int16_t adoffset_active;
int32_t reg_dref;
int16_t max_presc_val;
int16_t no_pulses;
int16_t hall_tr2;
int16_t qep_count_init;
int16_t read_pos_value;
uint16_t change_spdctrl_lim;
int16_t time_old[3];
int16_t ref_inc;
uint16_t neg_mult_res;
int32_t sw_lim_neg;
int32_t sw_lim_pos;
uint16_t ml_event_mask_2;
uint16_t slave_position;
int16_t theta_filtered;
int32_t theta_filt_out1;
int32_t theta_filt_in;
int16_t delta_theta;
int16_t kp_tht;
int16_t ki_tht;
int16_t sh_p_tht;
int16_t sh_i_tht;
uint16_t time_limit;
int16_t i_tht_l;
int16_t i_tht_h;
float32_t theta_integral_part;
int16_t theta_tst;
int16_t theta_tst1;
int16_t execute_t_mode;
int16_t i_q_test;
int16_t angle_inc;
uint16_t time_elapsed;
int32_t filt_a;
int32_t filt_b;
uint16_t master_id2;
int16_t move_state;
int32_t start_position;
int32_t first_position;
int32_t final_position;
int16_t init_angle;
int32_t digin_mask_long;
int32_t digin_status_ds402_1;
uint16_t homing_time;
uint16_t ena_pin_info;
uint32_t dtmin;
uint32_t dtmax;
int32_t speed_scaling_factor;
int32_t endat_temp2;
int32_t spd_est;
int16_t vm_temp2;
int16_t endat_temp;
int16_t host_address;
int16_t r_shift;
int16_t u_ri_scaling;
int16_t u_ri_shift;
int16_t speed_u_ri;
uint32_t time_lim;
int16_t speed_ns;
uint16_t al_status;
int16_t d_i_q;
int16_t l_scaling;
int16_t l_shift;
int32_t spd_err_long;
uint32_t enc_margin;
uint32_t max_enc_margin;
int16_t endat_no_rev;
int16_t bldc_sin;
int16_t endat_fract;
int16_t endat_res;
int16_t pos_delta_t;
int16_t offset_detect;
int16_t debug;
int16_t jerk0_int;
uint32_t jerk0_fr;
int32_t time_jerk;
int32_t time_2;
int32_t time_4;
int32_t time_jerk_rg;
int32_t time_2_rg;
int32_t time_4_rg;
int16_t nlines_el_rev;
int16_t cqep2theta;
float64_t sc_acc;
float64_t sc_spd;
float64_t c_spd_fl;
int32_t c_ref_final;
uint32_t interpolation_counter;
uint32_t interpolation_period;
int16_t jerk_int;
uint32_t jerk_fr;
int16_t jerk2_int;
uint32_t jerk2_fr;
int16_t jerk6_int;
uint32_t jerk6_fr;
int16_t jerki_int;
uint32_t jerki_fr;
int16_t jerki2_int;
uint32_t jerki2_fr;
int16_t jerki6_int;
uint32_t jerki6_fr;
int32_t c_ref_1;
uint32_t sc_seg_time;
uint32_t counter_sc;
int16_t sc_seg_no;
uint32_t sc_time;
uint32_t const_1_6;
int32_t sc_c_pos;
int16_t adc_trigger_offset;
int16_t axis_id_5_bit;
boolean_t has_dc_motor_on_ac_phases;
boolean_t uses_dc_motor_on_ac_phases;
boolean_t uses_ic_lo_quadsampling;
boolean_t uses_dual_scale_simultaneous_oversampled_measurements_on_c;
boolean_t uses_dual_scale_simultaneous_oversampled_measurements_on_a;
uint16_t sincos_oversampling;
uint16_t linhalls_oversampling;
uint16_t currents_oversampling;
uint16_t uses_eru0_lsn;
boolean_t has_crt_gain_selectable;
boolean_t has_different_thresholds;
/* motor_digital_halls:
 * 0 = digital halls disconnected, inputs not analyzed as halls
 * 1 = digital halls connected, analyzed and error triggering is active
 * 2 = digital halls connected, analyzed but error triggering is skipped */
uint16_t motor_digital_halls;

int16_t ram_address;		/* XXX: no longer used ??? */
int16_t value_ram;			/* XXX: no longer used ??? */
int16_t size_eng;			/* XXX: no longer used ??? */
uint16_t checksum_st;		/* XXX: no longer used ??? */
int16_t valid_table;		/* XXX: no longer used ??? */
int16_t table_sa;			/* XXX: no longer used ??? */
uint16_t checksum_e2rom;	/* XXX: no longer used ??? */
uint16_t volatile mer;				/* [MER] MOTION ERROR REGISTER */
uint16_t reg_t_pif;
int32_t reg_t_pi;
int16_t wd_reset;
uint16_t dref_fr;
int32_t cam_input;
int32_t cam_x_scf;
int32_t cam_y_scf;
uint16_t digin_status;
uint16_t srl_1;
uint16_t digin_inversion_mask;
uint16_t digout_inversion_mask;
uint16_t digin_active_level;
uint16_t first_start_bldc;
uint16_t volatile srl;	/* [SRL] STATUS REGISTER LOW */
uint16_t volatile srh;	/* [SRH] STATUS REGISTER HIGH */
uint16_t inside_pos_window;
uint16_t srh_int;
uint16_t volatile acr;	/* [ACR] AUXILIARY CONTROL REGISTER */
uint16_t aar_table;
int16_t flag_tml_instruction;
int16_t sat_val_cmp_ini;
uint16_t fdbk2_qep_rev_counting;
uint16_t sincos_fract_ld;
uint32_t qual_bq2;
int32_t postrigg_1;
int32_t postrigg_2;
int32_t postrigg_3;
int32_t postrigg_4;
int32_t postrigg_1_1;
int32_t postrigg_2_1;
int32_t postrigg_3_1;
int32_t postrigg_4_1;
int16_t ignore_postrigg_change;
int16_t cmpb_inin;
uint16_t checksum_eng_for_save;	/* XXX: no longer used ??? */
int16_t table_configuration_id;
int16_t checksum_save;			/* XXX: no longer used ??? */
int16_t enable_off;
int16_t enable_off_1;
uint16_t master_id;
uint16_t cbr_table;
uint16_t flag_msg_send;
int16_t send_ack;
int16_t disable_send_pvtsts;
int32_t crt_seg_pvt_spd;
int32_t sync_error;
int32_t sync_error_bkup;
int16_t sync_filter_min;
int16_t sync_filter_max;
int16_t original_pwm_period;
//int16_t sync_margin;
//int16_t sync_rate;
int16_t sync_increment;
uint32_t master_time;
uint32_t master_time_1;
uint32_t slow_loop_time;
uint32_t master_time_new_sync_1;
int32_t master_offset_time;
int32_t slave_offset_time;
uint32_t slave_base_time;
int16_t t1pr_old;
int16_t sync_status;
uint32_t absolute_position_fdbk1;
uint32_t absolute_position_fdbk2;
int32_t master_offset_modulo;
int32_t master_increment;
uint32_t rg_sampling;
int16_t t1cnt_buf;
int16_t gptcona_buf;
int16_t absolute_time_rem;
uint32_t slave_base_time_stop;
uint32_t axis_absolute_time;
uint32_t sync_cycle;
uint32_t ml_time_sync;
uint32_t can_sync_time;
int16_t send_master_offset;
int16_t ki_spd_est;
int32_t master_increment_inst;
int32_t slave_offset_time_new_sync;
int16_t slow_loop_samples;
int16_t flag_active_fast;
int32_t pos_2theta_filt;
int32_t target_position_1;
int32_t target_position_2;
int32_t target_position_fast;
int16_t kp_spd_est;
int16_t est_spd;
int32_t int_spd_est;
int16_t pos_2theta_p;
int16_t pulse_dir_initialized;
uint16_t srlh_mask;
uint16_t srh_mask;
uint16_t mer_1;
uint16_t mer_1_copen;
uint16_t mer_mask;
uint16_t der2_mask;
uint16_t srl_mask;
uint16_t digin_status_1;
uint16_t digin_status_mask;
uint16_t srh_1;		/* [SRH] STATUS REGISTER HIGH */
uint16_t k_scaling_speed;
int16_t enc_speed;
uint16_t timeout_reached;
uint32_t wait_time32;
int32_t div_a32;
int32_t div_r32;
int32_t time_1;
int16_t div_b16;
int16_t skip_can_msg;
int16_t skip_can_msg_value;
int16_t var_i3;
int32_t i2t_integral_drive;
int32_t ia_i2t_integral_drive;
int32_t ib_i2t_integral_drive;
int32_t ic_i2t_integral_drive;
int32_t i2t_integral_warning_drive;
uint16_t pos_controller_sat_l_part;
uint16_t interpolation_time_val;
int16_t interpolation_time_index;
int32_t i2t_integral_limit_drive;
int16_t i_q_ref_filt_ct;
int16_t tml_int_period;
int32_t ecam_init_pos;
int16_t i_i2tprot_drive;
int16_t i_i2tprot_drive_phase;
int16_t i_q_ref_filtered;
int32_t volatile apos_mot;
int32_t load_speed;
int32_t volatile can_load_speed;
int16_t sf_i2t_drive;
int16_t sf_i2t_drive_phase;
uint16_t sci_br_table;
int16_t i_q_ref_temp;
int16_t start_rtc;
uint32_t wait2sendack;
int32_t homepos;
int32_t homespd;
uint16_t flag_ping;
int16_t temp_kernel;
uint16_t execute_autotuning_st_addr;
uint16_t adc_10reference_offset;
uint16_t adc_10feedback_offset;
int16_t var_filtered;
uint16_t var_filt_ct;
uint16_t p_plot_var;
uint16_t avg_refhigh_value;
uint16_t checksum_read;
uint32_t checksum_address;
uint16_t receive_temp_buffer[6];
uint32_t rw_config_register;
uint32_t data_to_write;
uint32_t data_to_read;
uint32_t write_data_address;
uint16_t tml_fct;
uint16_t control_word;
uint16_t control_word_1;
uint16_t tml_tr;
uint16_t modes_of_operation;
uint16_t modes_of_operation_1;
uint16_t modes_of_operation_display;
uint16_t current_scale_type;
uint16_t crt_gain_selected;
uint16_t current_scale_amplification;
uint16_t power_stage_csa_register_calibration;
uint16_t power_stage_csa_register_normal;
uint16_t skip_hi_scale_currents;
uint16_t homing_nr;
uint16_t digout_status;
uint16_t select_can_mode;
int32_t pos_err_long;
int16_t motion_profile_type;
uint16_t cam_e2rom_load_address;
uint16_t non_compare_event_ctrl;
uint16_t execute_main_tml;
uint16_t init_tables_p;
uint16_t start_address_h;
uint32_t tml_sw_ver;
uint16_t copy_of_digin_status;
uint16_t copy_of_mer;
uint16_t status_ds402_2;
uint16_t cop_1s_timer;
uint16_t start_address_tr;
uint16_t start_address_fct;
uint32_t input_cfg_3_0[3];		/* TODO check if it is really an array or not */
uint32_t input_cfg_7_4;
uint32_t input_cfg_11_8;
uint32_t input_cfg_15_12;
uint32_t output_cfg_3_0;
uint32_t output_cfg_7_4;
uint32_t output_cfg_11_8;
uint32_t output_cfg_15_12;
int32_t real_c_pos;
uint16_t ad_res_2_filt;
int16_t ad2_filt_ct;
int32_t real_c_acc;
int32_t real_c_dec;
int32_t real_c_spd;
int32_t err_prot_long;
int32_t real_pos;
uint16_t volatile status_ds402;
int16_t interpolation_submode_select;
uint16_t status_ds402_1;
uint16_t special_ios_position;
int32_t checksum_long;
uint16_t flag_stop_pvt_pt;
uint16_t ad_res_9;
uint32_t srh_srl;
int16_t comm_error_option_code;
int16_t fault_reaction_option_code;
uint16_t at_ref_index;
int16_t atr;
uint16_t at_ref_start_addr;
uint16_t at_ref_max_points;
int16_t sto_hw_err_timeout;
uint16_t brake_apply_delay;
uint16_t brake_release_delay;
int16_t apply_torque;
uint16_t err_min_fc;
uint16_t err_max_fc;
uint16_t ton_err_min_fc;
uint16_t contor_err_min_fc;
uint16_t fdbk1_powerup_timeout;
uint16_t fdbk2_powerup_timeout;
uint16_t start_mode_command;
uint16_t adv_start_retries;

uint32_t status_register;
uint16_t volatile ssr;	/* [SSR] SLAVE STATUS REGISTER */
uint32_t velocity_bandwidth_iu;
uint16_t velocity_treshold;
uint16_t velocity_treshold_iu;
int16_t sat_val_cmp;
uint16_t interpolation_time_val;
int16_t interpolation_time_index;
uint16_t is6060_received;

int32_t target_c_spd;
int16_t motor_current;
int16_t motor_current_copen;
int16_t target_torque;
uint16_t auxiliary_settings_register;
int16_t halt_op_oc;

uint16_t volatile status_word_int;

int32_t min_pos_range;
int32_t max_pos_range;
uint16_t pos_range_defined;
uint32_t pos_opt_code;
uint16_t fdbk1_bits_ign_st;
uint16_t fdbk1_bits_ign_mt;
uint16_t fdbk2_bits_ign_st;
uint16_t fdbk2_bits_ign_mt;
int32_t target_position_4_plot;
uint16_t polarity;
int16_t linear_hall_3_raw;
uint32_t serial_number;
uint16_t bq_mask;
uint16_t new_int_sat;
uint16_t sin_offset;
uint16_t cos_offset;
uint16_t sin_gain;
uint16_t cos_gain;
int16_t sineps;
int16_t coseps;
uint16_t flag_filt;
uint16_t encpulses_limit;
float32_t a1_spd_est_bq_f;
float32_t a2_spd_est_bq_f;
float32_t b0_spd_est_bq_f;
float32_t b1_spd_est_bq_f;
float32_t b2_spd_est_bq_f;
uint16_t rev_spd_ampl;
uint16_t white_noise;
uint16_t i_q_ref_slow;
uint16_t pos_err_abs_val;
uint16_t pos_err_abs_val_temp;
uint16_t biss_small_timeout;
uint16_t new_impl_pos_ssi;
uint32_t spd_bdac_min;
uint32_t spd_bdac_max;
uint16_t pos_hall_off_temp;
uint16_t gs_index_ct;
uint16_t gs_index_filt;
uint16_t gs_index_no_filt;
uint32_t pos_bldc;
int16_t spdsinacqslow_corrected;
int16_t spdcosacqslow_corrected;
uint16_t coeff_d_pos;
uint16_t max_spd_dualuse;
uint16_t hall_max_spd_dualuse;
uint16_t high_spd_loop_counter;
uint32_t high_Spd_limit;
uint32_t low_Spd_limit;
uint16_t low_spd_loop_counter;
uint16_t special_ios_status;

/*================================================================
 * Sine / Chirp variables and parameters
 *============================================================= */
int32_t dtheta0;
int32_t dtheta_inc;
int32_t ampl0;
int32_t ampl_inc;
int32_t sin_n;
int16_t phase0;
int16_t first_sine;
int32_t sin_angle;
int32_t sin_angle_inc;
int32_t sine_wave;
int32_t sin_cntr;
int32_t sin_a;
int32_t sine_wave_1;
int32_t sin_n_rg;
int32_t ampl_sat;
int32_t dtheta_inc_sat;
int32_t sin_a_sat;
int32_t sin_angle_inc_sat;
int32_t sin_angle_inc_rg;
int32_t sin_a_inc;

uint16_t counter_pvt;
uint16_t pvt_active;
uint16_t pt_time;
int32_t real_sw_negative_limit;
int32_t real_sw_positive_limit;

/*================================================================
 * Gain scheduling variables
 *============================================================= */
uint16_t gs_table[GS_MAX_LEN];
int16_t gs_index;
int16_t gs_index_1;
uint16_t gs_counter;
uint16_t gs_crt_addr;
uint16_t *p_gs_param;
uint16_t *p_gs_data;
uint16_t *p_gs_table;
uint16_t gs_error;
int16_t gs_best_settling_type;
int32_t gs_speed;
int32_t *p_gs_trig;
int16_t gs_i_min;
int16_t gs_i_max;
int32_t gs_value_1;
int16_t gs_steps;
int16_t gs_man_1;
uint16_t gs_trig_addr;
int32_t gs_trig_value;
int32_t gs_trig_value_1;
uint16_t gs_k_poserr;
uint16_t gs_start_addr;
int16_t gs_max_elem;
int16_t gs_words;
int16_t gs_type;
int16_t gs_man;
uint16_t gs_time;
uint16_t gs_param[26];
int16_t analogue_reference;
/*================================================================
 * BIQUAD filters variables
 *============================================================= */
t_bq_f_coeff bq_f_coeff[MAX_BIQUAD];
t_bq_f_hist bq_f_hist[MAX_BIQUAD];
uint32_t l_user_var1;
uint32_t l_user_var2;
uint32_t l_user_var3;
uint32_t l_user_var4;
uint16_t aspd_bq;
uint16_t iqref_bq;
uint16_t spdref_bq;
/*================================================================
 * Absolute encoder variables
 *============================================================= */
uint16_t encoder_type_motor;
uint16_t encoder_type_load;
uint16_t encoder_status_fdbk1;
uint16_t encoder_status_fdbk2;
uint16_t encoder_command_fdbk1;
uint16_t encoder_command_fdbk2;

uint16_t esm_float_support;
uint16_t tml_int13_configuration;
uint16_t tml_input_status_1;


uint32_t debug_address;
uint32_t debug_data;
uint16_t debug_operation;
uint16_t debug_error_register;
uint16_t debug_data_size;
uint32_t debug_set_mask;
uint32_t debug_reset_mask;
uint16_t dsp_debug_active;

uint16_t new_freeze_control;
int16_t ref_voltage_computed;
int16_t u_q_ref_freeze;
int16_t u_q_ref_freeze_lim;
int16_t u_d_ref_freeze;
uint16_t logger_delayed_start;
uint16_t logger_from_axis_off;

int32_t t_si_brut;
int32_t t_ai_brut;
int32_t t_si1_filt;
int32_t t_ai_no_filter;
int32_t tacc_threshold_pos;
int32_t tacc_threshold_neg;
float32_t a1_tspd;
float32_t b0_tspd;
float32_t dn_1_filter_tspd;
float32_t a1_tacc;
float32_t b0_tacc;
float32_t dn_1_filter_tacc;
uint16_t tacc_filter_option;
uint16_t wait_tspd_0;
uint16_t counter_wait_tspd_0;
uint16_t encoder_filtering_fdbk1;
uint16_t encoder_filtering_fdbk2;
uint16_t comm_error_flagged;
uint16_t k_spd_err;

uint16_t endat_treshold_clock_cycles;
int16_t endat_additional_clock;
int16_t endat_additional_option;

int16_t can_show_filtered_var;
int32_t var_bq_filtered;
uint16_t bq_var_address;
uint16_t bq_var_type;
int32_t *p_bq_var_address;
float32_t var_bq_dn;
float32_t var_bq_dn_1;
float32_t var_bq_a1;
float32_t var_bq_b0;
int16_t read_internal_temp;
int16_t io_error_fault_state;

/* Variables for the new SOL + PID implementation*/
uint16_t tonerr_sol_pid;
int32_t errprot_sol_pid;

uint16_t analog_id0;
uint16_t analog_id1;
uint16_t analog_id2;

boolean_t brake_as_MCIV;
/*************************************************************************
*	LEGACY MEMORY PAGE @ 200h
*************************************************************************/
void *p_tml_data_pg200[TML_DATA_TABLE_SIZE_PG200] __attribute__ ((aligned (4))) =
{
	/*================================================================
	 * Motion Control Variables. Internal use. Part 1.
	 *============================================================= */
	LSW_ADDRESS_OF(number_of_drive_inputs),		// [0x200]
	LSW_ADDRESS_OF(asr),						// [0x201]
	LSW_ADDRESS_OF(fast_loop_counter),			// [0x202]
	LSW_ADDRESS_OF(slow_loop_counter),			// [0x203]
	LSW_ADDRESS_OF(number_of_drive_outputs),	// [0x204]
	LSW_ADDRESS_OF(tmp_slow[0]),				// [0x205]
	LSW_ADDRESS_OF(tmp_slow[1]),				// [0x206]
	LSW_ADDRESS_OF(tmp_slow[2]),				// [0x207]
	LSW_ADDRESS_OF(tmp_slow[3]),				// [0x208]
	LSW_ADDRESS_OF(tmp_fast[0]),				// [0x209]
	LSW_ADDRESS_OF(tmp_fast[1]),				// [0x20a]
	LSW_ADDRESS_OF(tmp_fast[2]),				// [0x20b]
	LSW_ADDRESS_OF(tmp_fast[3]),				// [0x20c]
	LSW_ADDRESS_OF(new_actr_value_or_time_0),	// [0x20d]
	MSW_ADDRESS_OF(stepper_sol_dtheta_fast),	// [0x20e]
	LSW_ADDRESS_OF(theta_fract_sol),			// [0x20f]
	LSW_ADDRESS_OF(fdbk1_new_position),			// [0x210]
	LSW_ADDRESS_OF(fdbk1_old_position),			// [0x211]
	LSW_ADDRESS_OF(pos_2theta_1),				// [0x212]
	LSW_ADDRESS_OF(hall_1),						// [0x213]	// _sin_theta_resolver
	LSW_ADDRESS_OF(pos_err_1),					// [0x214]
	LSW_ADDRESS_OF(current_id),					// [0x215]
	LSW_ADDRESS_OF(cvdc_table_index),			// [0x216]
	LSW_ADDRESS_OF(fdbk1_encoder_baudrate),		// [0x217]
	LSW_ADDRESS_OF(fdbk1_bits_st),				// [0x218]
	LSW_ADDRESS_OF(fdbk1_bits_mt),				// [0x219]
	LSW_ADDRESS_OF(fdbk1_bits_ign_st),			// [0x21a]
	LSW_ADDRESS_OF(fdbk1_bits_ign_mt),			// [0x21b]
	LSW_ADDRESS_OF(fdbk1_powerup_timeout),		// [0x21c]
	LSW_ADDRESS_OF(fdbk1_is_gray_coded),		// [0x21d]
	LSW_ADDRESS_OF(null_padding_variable),		// [0x21e]
	LSW_ADDRESS_OF(sat_out_spd_1),				// [0x21f]
	LSW_ADDRESS_OF(pos_inc),					// [0x220]
	LSW_ADDRESS_OF(electric_position),			// [0x221]	// _sin_coeff_temp / _res_ex2
	/*================================================================
	 * Motion Control Variables. User has read access for data logging
	 *============================================================= */
	LSW_ADDRESS_OF(pos_2theta),					// [0x222]
	LSW_ADDRESS_OF(load),						// [0x223]	// _theta_t
	LSW_ADDRESS_OF(theta),						// [0x224]
	LSW_ADDRESS_OF(sin_theta),					// [0x225]
	LSW_ADDRESS_OF(cos_theta),					// [0x226]
	LSW_ADDRESS_OF(hall),						// [0x227]	// _cos_theta_resolver / _omgs
	LSW_ADDRESS_OF(apos_load),					// [0x228]
	MSW_ADDRESS_OF(apos_load),					// [0x229]
	LSW_ADDRESS_OF(pos_err),					// [0x22a]
	LSW_ADDRESS_OF(spd_ref),					// [0x22b]
	LSW_ADDRESS_OF(motor_speed),				// [0x22c]
	MSW_ADDRESS_OF(motor_speed),				// [0x22d]
	LSW_ADDRESS_OF(spd_err),					// [0x22e]
	LSW_ADDRESS_OF(i_q_ref),					// [0x22f]
	LSW_ADDRESS_OF(i_q),						// [0x230]
	LSW_ADDRESS_OF(crt_err),					// [0x231]
	LSW_ADDRESS_OF(u_q_ref),					// [0x232]
	LSW_ADDRESS_OF(i_d_ref),					// [0x233]
	LSW_ADDRESS_OF(i_d),						// [0x234]
	LSW_ADDRESS_OF(u_d_ref),					// [0x235]
	LSW_ADDRESS_OF(u_a_ref),					// [0x236]
	LSW_ADDRESS_OF(u_b_ref),					// [0x237]
	LSW_ADDRESS_OF(u_c_ref),					// [0x238]
	LSW_ADDRESS_OF(current_ia),					// [0x239]
	LSW_ADDRESS_OF(current_ib),					// [0x23a]
	LSW_ADDRESS_OF(current_ic),					// [0x23b]
	LSW_ADDRESS_OF(ad_res_0),					// [0x23c]
	LSW_ADDRESS_OF(ad_res_1),					// [0x23d]
	LSW_ADDRESS_OF(adc_feedback_unfiltered),	// [0x23e]
	LSW_ADDRESS_OF(adc_encoder_sin),			// [0x23f]
	LSW_ADDRESS_OF(v_mot),						// [0x240]		//DC supply motor
	LSW_ADDRESS_OF(adc_reference),				// [0x241]
	LSW_ADDRESS_OF(adc_encoder_cos),			// [0x242]
	LSW_ADDRESS_OF(t_drive),					// [0x243]		//ad_res_7
	/*================================================================
	 * Motion Control Parameters. Part 1.
	 *============================================================= */
	LSW_ADDRESS_OF(offset_ad0_v),				// [0x244]
	LSW_ADDRESS_OF(offset_ad1_v),				// [0x245]
	LSW_ADDRESS_OF(offset_ad2_p),				// [0x246]
	LSW_ADDRESS_OF(linear_hall_2_offset),		// [0x247]
	LSW_ADDRESS_OF(offset_ad4_p),				// [0x248]
	LSW_ADDRESS_OF(offset_ad5_p),				// [0x249]
	LSW_ADDRESS_OF(linear_hall_1_offset),		// [0x24a]
	LSW_ADDRESS_OF(offset_ad7_p),				// [0x24b]
	LSW_ADDRESS_OF(cqep2theta_long),			// [0x24c]			// cqep2theta_long / pos_brut32 / adchannel01
	MSW_ADDRESS_OF(cqep2theta_long),			// [0x24d]	// adchannel23
	LSW_ADDRESS_OF(nlines_el_rev_long),			// [0x24e]	// nlines_el_rev_long / pos_brut32_1 / adchannel45
	MSW_ADDRESS_OF(nlines_el_rev_long),			// [0x24f]	// adchannel67
	LSW_ADDRESS_OF(fast_max_counts),			// [0x250]
	LSW_ADDRESS_OF(slow_max_counts),			// [0x251]
	LSW_ADDRESS_OF(pwm_period),					// [0x252]
	LSW_ADDRESS_OF(dbt),						// [0x253]
	LSW_ADDRESS_OF(u_sat_pwm),					// [0x254]
	LSW_ADDRESS_OF(gear_master),				// [0x255]	// _nnn
	LSW_ADDRESS_OF(gear_slave),					// [0x256]	//  MSB_ADDRESS_OF(gear_master)
	LSW_ADDRESS_OF(phase_adv),					// [0x257]	// hall_io_add_or_c_weak
	LSW_ADDRESS_OF(linear_hall_3_offset),		// [0x258]
	LSW_ADDRESS_OF(hall_config_or_theta_inc_weak),	// [0x259]
	LSW_ADDRESS_OF(v_dc_nominal),				// [0x25a]
	LSW_ADDRESS_OF(c_v_dc),						// [0x25b]
	LSW_ADDRESS_OF(c_analogue_in),				// [0x25c]
	LSW_ADDRESS_OF(sh_c_analogue_in),			// [0x25d]
	LSW_ADDRESS_OF(kp_pos),						// [0x25e]
	LSW_ADDRESS_OF(sh_p_pos),					// [0x25f]
	LSW_ADDRESS_OF(ki_pos),						// [0x260]
	LSW_ADDRESS_OF(sh_i_pos),					// [0x261]
	LSW_ADDRESS_OF(kd_pos),						// [0x262]
	LSW_ADDRESS_OF(sh_d_pos),					// [0x263]
	LSW_ADDRESS_OF(kdf_pos),					// [0x264]
	LSW_ADDRESS_OF(sat_out_pos),				// [0x265]
	LSW_ADDRESS_OF(sat_int_pos),				// [0x266]
	LSW_ADDRESS_OF(kp_spd),						// [0x267]
	LSW_ADDRESS_OF(sh_p_spd),					// [0x268]
	LSW_ADDRESS_OF(ki_spd),						// [0x269]
	LSW_ADDRESS_OF(sh_i_spd),					// [0x26a]
	LSW_ADDRESS_OF(sat_out_spd),				// [0x26b]
	LSW_ADDRESS_OF(sat_int_spd),				// [0x26c]
	LSW_ADDRESS_OF(kff_spd),					// [0x26d]
	LSW_ADDRESS_OF(kff_acc),					// [0x26e]
	LSW_ADDRESS_OF(kff_load),					// [0x26f]
	LSW_ADDRESS_OF(sh_kff),						// [0x270]
	LSW_ADDRESS_OF(kp_crt),						// [0x271]
	LSW_ADDRESS_OF(sh_p_crt),					// [0x272]
	LSW_ADDRESS_OF(ki_crt),						// [0x273]
	LSW_ADDRESS_OF(sh_i_crt),					// [0x274]
	LSW_ADDRESS_OF(sat_out_crtd),				// [0x275]
	LSW_ADDRESS_OF(sat_out_crtq),				// [0x276]
	LSW_ADDRESS_OF(nlines_el_rev_or_c_spd),		// [0x277]
	LSW_ADDRESS_OF(cqep2theta_or_sh_c_spd),		// [0x278]	// flag_correction
	LSW_ADDRESS_OF(linear_hall_3_gain),			// [0x279]
	LSW_ADDRESS_OF(homopolar_comp),				// [0x27a]
	LSW_ADDRESS_OF(i_d_ref_max),				// [0x27b]
	LSW_ADDRESS_OF(i_d_ref_min),				// [0x27c]
	LSW_ADDRESS_OF(boost_voltage),				// [0x27d]
	LSW_ADDRESS_OF(filter_coeficient),			// [0x27e] // filter_coefficient
	LSW_ADDRESS_OF(linear_hall_interpolation),	// [0x27f] // n2
	/*================================================================
	 * Motion Control Parameters. Part 2.
	 *============================================================= */
	LSW_ADDRESS_OF(increment_ref_test),			// [0x280]
	LSW_ADDRESS_OF(reference_test),				// [0x281]
	LSW_ADDRESS_OF(theta_test),					// [0x282]
	LSW_ADDRESS_OF(theta_inc_test_or_ho),		// [0x283]
	LSW_ADDRESS_OF(time_a),						// [0x284]
	LSW_ADDRESS_OF(time_b),						// [0x285]
	LSW_ADDRESS_OF(brake_control_register),		// [0x286]	// time_max
	LSW_ADDRESS_OF(linear_hall_1_gain),			// [0x287]	// pos_trigger / sin_coeff
	LSW_ADDRESS_OF(pos_long_compensation),		// [0x288]	//cos_coeff_temp  / start_sense
	LSW_ADDRESS_OF(exotic_position_offset),		// [0x289]	// offset_aphase
	LSW_ADDRESS_OF(level_brake_on),				// [0x28a]
	LSW_ADDRESS_OF(brake_duty_cycle),			// [0x28b]
	LSW_ADDRESS_OF(brake_off_level),			// [0x28c]
	LSW_ADDRESS_OF(linear_hall_1_max),			// [0x28d]	// sin_theta_max
	LSW_ADDRESS_OF(k_i_q),						// [0x28e]
	LSW_ADDRESS_OF(linear_hall_2_gain),			// [0x28f]
	LSW_ADDRESS_OF(sft_current),				// [0x290]
	LSW_ADDRESS_OF(sh_t_ai),					// [0x291]
	LSW_ADDRESS_OF(sh_t_si),					// [0x292]
	/*================================================================
	 * Protection Parameters.
	 *============================================================= */
	LSW_ADDRESS_OF(beta),						// [0x293]
	MSW_ADDRESS_OF(beta),						// [0x294]
	LSW_ADDRESS_OF(imax),						// [0x295]
	LSW_ADDRESS_OF(alpha),						// [0x296]
	MSW_ADDRESS_OF(alpha),						// [0x297]
	LSW_ADDRESS_OF(t1max),						// [0x298]
	LSW_ADDRESS_OF(t2max),						// [0x299]
	LSW_ADDRESS_OF(umax),						// [0x29a]
	LSW_ADDRESS_OF(umin),						// [0x29b]
	LSW_ADDRESS_OF(n_max),						// [0x29c]
	LSW_ADDRESS_OF(filter_1),					// [0x29d]
	/*================================================================
	 * ReferenceGenerator Inputs. Command parameters.
	 *============================================================= */
	LSW_ADDRESS_OF(c_pos),						// [0x29e]
	MSW_ADDRESS_OF(c_pos),						// [0x29f]
	LSW_ADDRESS_OF(c_spd),						// [0x2a0]
	MSW_ADDRESS_OF(c_spd),						// [0x2a1]
	LSW_ADDRESS_OF(c_acc),						// [0x2a2]
	MSW_ADDRESS_OF(c_acc),						// [0x2a3]
	LSW_ADDRESS_OF(c_dref),						// [0x2a4]
	(int32_t*)MSB_ADDRESS_OF(c_dref),			// [0x2a5]
	LSW_ADDRESS_OF(c_time),						// [0x2a6]
	LSW_ADDRESS_OF(asr2),						// [0x2a7]	// lsw_stop
	LSW_ADDRESS_OF(c_ref),						// [0x2a8]
	MSW_ADDRESS_OF(c_ref),						// [0x2a9]
	LSW_ADDRESS_OF(m_ref),						// [0x2aa]	//m_ref
	MSW_ADDRESS_OF(m_ref),						// [0x2ab]	//m_ref
	LSW_ADDRESS_OF(eg_ratio),					// [0x2ac]
	MSW_ADDRESS_OF(eg_ratio),					// [0x2ad]
	/*================================================================
	 * ReferenceGenerator Outputs. Read-only computed parameters.
	 *============================================================= */
	LSW_ADDRESS_OF(ref),						// [0x2ae]
	MSW_ADDRESS_OF(ref),						// [0x2af]
	LSW_ADDRESS_OF(mcr_1),						// [0x2b0]
	LSW_ADDRESS_OF(t_pif),						// [0x2b1]
	LSW_ADDRESS_OF(t_pi),						// [0x2b2]
	MSW_ADDRESS_OF(t_pi),						// [0x2b3]
	LSW_ADDRESS_OF(t_si),						// [0x2b4]
	MSW_ADDRESS_OF(t_si),						// [0x2b5]
	LSW_ADDRESS_OF(t_ai),						// [0x2b6]
	MSW_ADDRESS_OF(t_ai),						// [0x2b7]
	/*================================================================
	 * Other ML parameters.
	 *============================================================= */
	LSW_ADDRESS_OF(pos0),						// [0x2b8]
	MSW_ADDRESS_OF(pos0),						// [0x2b9]
	LSW_ADDRESS_OF(pos_rel),					// [0x2ba]
	MSW_ADDRESS_OF(pos_rel),					// [0x2bb]
	LSW_ADDRESS_OF(cap_pos),					// [0x2bc]
	MSW_ADDRESS_OF(cap_pos),					// [0x2bd]
	LSW_ADDRESS_OF(ml_time0),					// [0x2be]
	MSW_ADDRESS_OF(ml_time0),					// [0x2bf]
	LSW_ADDRESS_OF(ml_time),					// [0x2c0]
	MSW_ADDRESS_OF(ml_time),					// [0x2c1]
	LSW_ADDRESS_OF(ml_rtime),					// [0x2c2]
	MSW_ADDRESS_OF(ml_rtime),					// [0x2c3]
	/*================================================================
	 * Motion Control Parameters. Part 3.
	 *============================================================= */
	LSW_ADDRESS_OF(tonimax),					// [0x2c4]
	LSW_ADDRESS_OF(errprot),					// [0x2c5]
	LSW_ADDRESS_OF(tonerr),						// [0x2c6]
	LSW_ADDRESS_OF(spd_ref_lim),				// [0x2c7]	// spd_ref_lim //earth_fault_level
	/*================================================================
	 * ReferenceGenerator Variables. Internal use.
	 *============================================================= */
	LSW_ADDRESS_OF(c_a),						// [0x2c8]
	MSW_ADDRESS_OF(c_a),						// [0x2c9]
	LSW_ADDRESS_OF(c_1a),						// [0x2ca]
	MSW_ADDRESS_OF(c_1a),						// [0x2cb]
	LSW_ADDRESS_OF(dref),						// [0x2cc]	// _dref
	MSW_ADDRESS_OF(dref),						// [0x2cd]	// _dref
	LSW_ADDRESS_OF(rg_p),						// [0x2ce]	// rg_p
	MSW_ADDRESS_OF(rg_p),						// [0x2cf]	// rg_p
	LSW_ADDRESS_OF(rg_ss),						// [0x2d0]	// rg_ss
	MSW_ADDRESS_OF(rg_ss),						// [0x2d1]	// rg_ss
	LSW_ADDRESS_OF(rg_js),						// [0x2d2]	// t_aif_sc
	MSW_ADDRESS_OF(rg_js),						// [0x2d3]	// t_sif_sc
	LSW_ADDRESS_OF(rg_a),						// [0x2d4]	// t_pif_sc
	MSW_ADDRESS_OF(rg_a),						// [0x2d5]	// sc_seg_no / counter_pvt
	LSW_ADDRESS_OF(rg_1a),						// [0x2d6]	// counter_sc / a_pvt_a_int
	(uint32_t*)MSB_ADDRESS_OF(rg_1a),			// [0x2d7]
	LSW_ADDRESS_OF(rg_s),						// [0x2d8]	// a_pvt_a_fr / jerki_fr
	MSW_ADDRESS_OF(rg_s),						// [0x2d9]
	LSW_ADDRESS_OF(rg_ti),						// [0x2da]	// jerki_int
	LSW_ADDRESS_OF(rg_p0if),					// [0x2db]	// jerki2_int
	LSW_ADDRESS_OF(rg_p0i),						// [0x2dc]	// jerki2_fr
	MSW_ADDRESS_OF(rg_p0i),						// [0x2dd]
	LSW_ADDRESS_OF(rg_pdi),						// [0x2de]	// jerki6_fr
	MSW_ADDRESS_OF(rg_pdi),						// [0x2df]
	LSW_ADDRESS_OF(t_dpi),						// [0x2e0]
	MSW_ADDRESS_OF(t_dpi),						// [0x2e1]
	LSW_ADDRESS_OF(t_si1),						// [0x2e2]
	MSW_ADDRESS_OF(t_si1),						// [0x2e3]
	LSW_ADDRESS_OF(m_ref1),						// [0x2e4]
	MSW_ADDRESS_OF(m_ref1),						// [0x2e5]
	LSW_ADDRESS_OF(rg_temp1),					// [0x2e6]	// cam_temp
	MSW_ADDRESS_OF(rg_temp1),					// [0x2e7]
	LSW_ADDRESS_OF(rg_temp2),					// [0x2e8]	// cam_ind
	MSW_ADDRESS_OF(rg_temp2),					// [0x2e9]	// cam_rem
	LSW_ADDRESS_OF(rg_pdif),					// [0x2ea]	// jerki6_int
	LSW_ADDRESS_OF(rg_temp3f),					// [0x2eb]	// cam_step
	LSW_ADDRESS_OF(rg_temp3),					// [0x2ec]	// cam_masterrelpos
	MSW_ADDRESS_OF(rg_temp3),					// [0x2ed]
	/*================================================================
	 * Motion Control Variables. Internal use. Part 2.
	 *============================================================= */
	LSW_ADDRESS_OF(stall_lim),					// [0x2ee]	// contor_1
	LSW_ADDRESS_OF(ref_high),					// [0x2ef]
	LSW_ADDRESS_OF(sign),						// [0x2f0]	// gm_send_bsy
	LSW_ADDRESS_OF(eg_init),					// [0x2f1]
	LSW_ADDRESS_OF(spd_ref_long),				// [0x2f2]	// _btimeout / position_zero_ssi
	MSW_ADDRESS_OF(spd_ref_long),				// [0x2f3]	// posspd_init
	LSW_ADDRESS_OF(fdbk1_encoder_sense),		// [0x2f4]
	LSW_ADDRESS_OF(comm_channel_type),			// [0x2f5]
	LSW_ADDRESS_OF(flag_t_undflw),				// [0x2f6]
	LSW_ADDRESS_OF(pos_2theta_filtered),		// [0x2f7]	// pos_2theta_filtered / pwm_pooling_adc
	LSW_ADDRESS_OF(pos_2theta_filtered_integral),	// [0x2f8]	// pos_2theta_filtered_integral / random_number
	LSW_ADDRESS_OF(fdbk2_encoder_sense),		// [0x2f9]	// ssi_sense / pos_delta_apos / flag_speed_too_low
	LSW_ADDRESS_OF(t_prescaler),				// [0x2fa]	// _mult / exotic_feedback_cmp / pos_delta_apos_1
	LSW_ADDRESS_OF(flag_uv),					// [0x2fb]
	LSW_ADDRESS_OF(u_offset),					// [0x2fc]	// t_con_value / pos_brut_32_rest
	LSW_ADDRESS_OF(linear_hall_1_min),			// [0x2fd]	// k_omega / sin_theta_min
	LSW_ADDRESS_OF(linear_hall_2_max),			// [0x2fe]	// cos_theta_max / k_uphase
	LSW_ADDRESS_OF(u_stbycrt),					// [0x2ff]	// acceleration / resolver_amplitude
	/*================================================================
	 * Motion Language Kernel and TIMC Registers
	 *============================================================= */
	LSW_ADDRESS_OF(scr),						// [0x300]
	LSW_ADDRESS_OF(cer),						// [0x301]
	LSW_ADDRESS_OF(osr),						// [0x302]
	LSW_ADDRESS_OF(pcr),						// [0x303]
	LSW_ADDRESS_OF(icr),						// [0x304]
	LSW_ADDRESS_OF(der2),						// [0x305]		// pcr_1
	LSW_ADDRESS_OF(isr),						// [0x306]
	LSW_ADDRESS_OF(p_int_table),				// [0x307]		//TML interrupt table address
	LSW_ADDRESS_OF(msr),						// [0x308]
	LSW_ADDRESS_OF(mcr),						// [0x309]
	LSW_ADDRESS_OF(ccr),						// [0x30a]
	LSW_ADDRESS_OF(csr),						// [0x30b]
	LSW_ADDRESS_OF(aar),						// [0x30c]
	LSW_ADDRESS_OF(cbr),						// [0x30d]
	LSW_ADDRESS_OF(ml_p[0]),					// [0x30e]
	LSW_ADDRESS_OF(ml_p[1]),					// [0x30f]
	LSW_ADDRESS_OF(ml_p[2]),					// [0x310]
	LSW_ADDRESS_OF(gearslave_id),				// [0x311]
	LSW_ADDRESS_OF(motor_on),					// [0x312]
	LSW_ADDRESS_OF(pp_ip1_break),				// [0x313]
	LSW_ADDRESS_OF(pp_ip2_break),				// [0x314]
	LSW_ADDRESS_OF(p_ip),						// [0x315]
	LSW_ADDRESS_OF(p_ip_sw),					// [0x316]
	LSW_ADDRESS_OF(p_ip_prog),					// [0x317]
	LSW_ADDRESS_OF(restore_ip),					// [0x318]
	LSW_ADDRESS_OF(p_ip_break),					// [0x319]
	LSW_ADDRESS_OF(pp_stack_pointer),			// [0x31a]
	LSW_ADDRESS_OF(mli_code),					// [0x31b]
	LSW_ADDRESS_OF(max_cor_err),				// [0x31c]
	LSW_ADDRESS_OF(mli_temp_0),					// [0x31d]
	LSW_ADDRESS_OF(mli_temp_1),					// [0x31e]
	LSW_ADDRESS_OF(ml_data[0]),					// [0x31f]
	LSW_ADDRESS_OF(ml_data[1]),					// [0x320]
	LSW_ADDRESS_OF(ml_data[2]),					// [0x321]
	LSW_ADDRESS_OF(ml_data[3]),					// [0x322]
	LSW_ADDRESS_OF(ml_comp_l),					// [0x323]
	LSW_ADDRESS_OF(ml_event_reg),				// [0x324]
	MSW_ADDRESS_OF(ml_event_reg),				// [0x325]
	LSW_ADDRESS_OF(ml_comp_r),					// [0x326]
	LSW_ADDRESS_OF(ml_event_mask),				// [0x327]
	LSW_ADDRESS_OF(drive_disabled),				// [0x328]
	LSW_ADDRESS_OF(mer_mask_1),					// [0x329]	// _crc
	LSW_ADDRESS_OF(index_value),				// [0x32a]
	/*================================================================
	 * Communication variables.
	 *============================================================= */
	LSW_ADDRESS_OF(download_count),				// [0x32b]
	LSW_ADDRESS_OF(data_length),				// [0x32c]
	LSW_ADDRESS_OF(timeout),					// [0x32d]
	LSW_ADDRESS_OF(p_ml_kernel_buffer),			// [0x32e]
	LSW_ADDRESS_OF(message_buffer[0].m_length),	// [0x32f]
	LSW_ADDRESS_OF(message_buffer[0].m_address),// [0x330]
	LSW_ADDRESS_OF(message_buffer[0].m_opcode),	// [0x331]
	LSW_ADDRESS_OF(message_buffer[0].m_data[0]),// [0x332]
	LSW_ADDRESS_OF(message_buffer[0].m_data[1]),// [0x333]
	LSW_ADDRESS_OF(message_buffer[0].m_data[2]),// [0x334]
	LSW_ADDRESS_OF(message_buffer[0].m_data[3]),// [0x335]
	LSW_ADDRESS_OF(message_buffer[1].m_length),	// [0x336]
	LSW_ADDRESS_OF(message_buffer[1].m_address),// [0x337]
	LSW_ADDRESS_OF(message_buffer[1].m_opcode),	// [0x338]
	LSW_ADDRESS_OF(message_buffer[1].m_data[0]),// [0x339]
	LSW_ADDRESS_OF(message_buffer[1].m_data[1]),// [0x33a]
	LSW_ADDRESS_OF(message_buffer[1].m_data[2]),// [0x33b]
	LSW_ADDRESS_OF(message_buffer[1].m_data[3]),// [0x33c]
	LSW_ADDRESS_OF(message_buffer[2].m_length),	// [0x33d]
	LSW_ADDRESS_OF(message_buffer[2].m_address),// [0x33e]
	LSW_ADDRESS_OF(message_buffer[2].m_opcode),	// [0x33f]
	LSW_ADDRESS_OF(message_buffer[2].m_data[0]),// [0x340]
	LSW_ADDRESS_OF(message_buffer[2].m_data[1]),// [0x341]
	LSW_ADDRESS_OF(message_buffer[2].m_data[2]),// [0x342]
	LSW_ADDRESS_OF(message_buffer[2].m_data[3]),// [0x343]
	LSW_ADDRESS_OF(message_buffer[3].m_length),	// [0x344]
	LSW_ADDRESS_OF(message_buffer[3].m_address),// [0x345]
	LSW_ADDRESS_OF(message_buffer[3].m_opcode),	// [0x346]
	LSW_ADDRESS_OF(message_buffer[3].m_data[0]),// [0x347]
	LSW_ADDRESS_OF(message_buffer[3].m_data[1]),// [0x348]
	LSW_ADDRESS_OF(message_buffer[3].m_data[2]),// [0x349]
	LSW_ADDRESS_OF(message_buffer[3].m_data[3]),// [0x34a]
	LSW_ADDRESS_OF(data_buffer[0]),				// [0x34b]
	LSW_ADDRESS_OF(data_buffer[1]),				// [0x34c]
	LSW_ADDRESS_OF(data_buffer[2]),				// [0x34d]
	LSW_ADDRESS_OF(takedata_timeout),			// [0x34e]
	/*================================================================
	 * SCI Variables.
	 *============================================================= */
	LSW_ADDRESS_OF(n_new_baudrate),				// [0x34f]
	LSW_ADDRESS_OF(p_rx_buffer),				// [0x350]
	MSW_ADDRESS_OF(p_rx_buffer),				// [0x351]
	LSW_ADDRESS_OF(p_tx_buffer),				// [0x352]
	MSW_ADDRESS_OF(p_tx_buffer),				// [0x353]
	LSW_ADDRESS_OF(default_io_fcn_register),	// [0x354]
	MSW_ADDRESS_OF(default_io_fcn_register),	// [0x355]
	LSW_ADDRESS_OF(is_forced_transition_2),		// [0x356]
	LSW_ADDRESS_OF(initial_alignment_performed),// [0x357]
	LSW_ADDRESS_OF(p_rx_pointer),				// [0x358]
	MSW_ADDRESS_OF(p_rx_pointer),				// [0x359]
	LSW_ADDRESS_OF(p_tx_pointer),				// [0x35a]
	MSW_ADDRESS_OF(p_tx_pointer),				// [0x35b]
	LSW_ADDRESS_OF(sci_tmprx),					// [0x35c]
	LSW_ADDRESS_OF(sci_tmptx),					// [0x35d]
	LSW_ADDRESS_OF(p_switch_rx_buffer),			// [0x35e]
	MSW_ADDRESS_OF(p_switch_rx_buffer),			// [0x35f]
	LSW_ADDRESS_OF(ad_filt),					// [0x360]
	MSW_ADDRESS_OF(ad_filt),					// [0x361]
	LSW_ADDRESS_OF(contor_imax),				// [0x362]
	LSW_ADDRESS_OF(contor_err),					// [0x363]
	LSW_ADDRESS_OF(contor_2),					// [0x364]
	LSW_ADDRESS_OF(log_ptr),					// [0x365]
	LSW_ADDRESS_OF(var_i1),						// [0x366]
	LSW_ADDRESS_OF(var_i2),						// [0x367]
	LSW_ADDRESS_OF(var_lf),						// [0x368]
	MSW_ADDRESS_OF(var_lf),						// [0x369]
	LSW_ADDRESS_OF(err_min),					// [0x36a]
	LSW_ADDRESS_OF(ton_err_min),				// [0x36b]
	LSW_ADDRESS_OF(contor_err_min),				// [0x36c]
	LSW_ADDRESS_OF(ml_stack[0]),				// [0x36d]
	LSW_ADDRESS_OF(ml_stack[1]),				// [0x36e]
	LSW_ADDRESS_OF(ml_stack[2]),				// [0x36f]
	""LSW_ADDRESS_OF"(ml_stack[3]),				// [0x370]"
	LSW_ADDRESS_OF(ml_stack[4]),				// [0x371]
	LSW_ADDRESS_OF(ml_stack[5]),				// [0x372]
	LSW_ADDRESS_OF(ml_stack[6]),				// [0x373]
	LSW_ADDRESS_OF(ml_stack[7]),				// [0x374]
	LSW_ADDRESS_OF(ml_stack[8]),				// [0x375]
	LSW_ADDRESS_OF(ml_stack[9]),				// [0x376]
	LSW_ADDRESS_OF(ml_stack[10]),				// [0x377]
	LSW_ADDRESS_OF(tml_int_time0),				// [0x378]
	LSW_ADDRESS_OF(tml_inactive),				// [0x379]
	LSW_ADDRESS_OF(speed_halls),				// [0x37a] p_txbuf_rd TODO restore
	MSW_ADDRESS_OF(speed_halls),				// [0x37b]
	LSW_ADDRESS_OF(transmission),				// [0x37c]	// [_transmition]
	MSW_ADDRESS_OF(transmission),				// [0x37d]
	LSW_ADDRESS_OF(aspd_mt_temp),				// [0x37e]
	MSW_ADDRESS_OF(aspd_mt_temp),				// [0x37f]
	/*================================================================
	 * CAN Variables.
	 *============================================================= */
	LSW_ADDRESS_OF(time_dimension_index),			// [0x380]		// time_dimension_index
	LSW_ADDRESS_OF(time_notation_index),			// [0x381]
	LSW_ADDRESS_OF(real_tonerr),					// [0x382]
	LSW_ADDRESS_OF(real_tonerrmin),					// [0x383]
	LSW_ADDRESS_OF(real_time_jerk),					// [0x384]
	LSW_ADDRESS_OF(real_spdtonerr),					// [0x385]
	LSW_ADDRESS_OF(position_factor.numerator),		// [0x386]
	MSW_ADDRESS_OF(position_factor.numerator),		// [0x387]
	LSW_ADDRESS_OF(position_factor.divisor),		// [0x388]
	MSW_ADDRESS_OF(position_factor.divisor),		// [0x389]
	LSW_ADDRESS_OF(velocity_factor.numerator),		// [0x38a]
	MSW_ADDRESS_OF(velocity_factor.numerator),		// [0x38b]
	LSW_ADDRESS_OF(velocity_factor.divisor),		// [0x38c]
	MSW_ADDRESS_OF(velocity_factor.divisor),		// [0x38d]
	LSW_ADDRESS_OF(acceleration_factor.numerator),	// [0x38e]
	MSW_ADDRESS_OF(acceleration_factor.numerator),	// [0x38f]
	LSW_ADDRESS_OF(acceleration_factor.divisor),	// [0x390]
	MSW_ADDRESS_OF(acceleration_factor.divisor),	// [0x391]
	LSW_ADDRESS_OF(time_factor.numerator),			// [0x392]
	MSW_ADDRESS_OF(time_factor.numerator),			// [0x393]
	LSW_ADDRESS_OF(time_factor.divisor),			// [0x394]
	MSW_ADDRESS_OF(time_factor.divisor),			// [0x395]
	LSW_ADDRESS_OF(pos_encoder.encoder_increments),	// [0x396]
	MSW_ADDRESS_OF(pos_encoder.encoder_increments),	// [0x397]
	LSW_ADDRESS_OF(pos_encoder.motor_revolutions),	// [0x398]
	MSW_ADDRESS_OF(pos_encoder.motor_revolutions),	// [0x399]
	LSW_ADDRESS_OF(feed_constant.numerator),		// [0x39a]
	MSW_ADDRESS_OF(feed_constant.numerator),		// [0x39b]
	LSW_ADDRESS_OF(master_settings),				// [0x39c]
	LSW_ADDRESS_OF(ext_ref_selection),				// [0x39d]
	LSW_ADDRESS_OF(save_config),					// [0x39e]
	LSW_ADDRESS_OF(homing_method),					// [0x39f]
	LSW_ADDRESS_OF(real_home_offset),				// [0x3a0]
	MSW_ADDRESS_OF(real_home_offset),				// [0x3a1]
	LSW_ADDRESS_OF(real_low_speed),					// [0x3a2]
	MSW_ADDRESS_OF(real_low_speed),					// [0x3a3]
	LSW_ADDRESS_OF(real_high_speed),				// [0x3a4]
	MSW_ADDRESS_OF(real_high_speed),				// [0x3a5]
	LSW_ADDRESS_OF(home_c_acc),						// [0x3a6]
	MSW_ADDRESS_OF(home_c_acc),						// [0x3a7]
	LSW_ADDRESS_OF(fdbk1_time_tr_txrx),				// [0x3a8]
	LSW_ADDRESS_OF(fdbk1_time_tr_rxtx),				// [0x3a9]
	LSW_ADDRESS_OF(fdbk2_time_tr_txrx),				// [0x3aa]
	LSW_ADDRESS_OF(fdbk2_time_tr_rxtx),				// [0x3ab]
	LSW_ADDRESS_OF(w_flag_can_buff),				// [0x3ac]
	LSW_ADDRESS_OF(der),							// [0x3ad]
	LSW_ADDRESS_OF(cam_ram_add),					// [0x3ae]
	LSW_ADDRESS_OF(cam_ram_st_add)					// [0x3af]
};

//#else MSB_ADDRESS_OF
/*************************************************************************
*	LEGACY MEMORY PAGE @ 800h
*************************************************************************/
void *p_tml_data_pg800[TML_DATA_TABLE_SIZE_PG800] __attribute__ ((aligned (4))) =
{
	LSW_ADDRESS_OF(linear_hall_1_raw),			// [0x800]
	LSW_ADDRESS_OF(linear_hall_2_raw),			// [0x801]
	LSW_ADDRESS_OF(t_rectangle),				// [0x802]
	LSW_ADDRESS_OF(hall_a_filt),				// [0x803]	// pos_comp_inc_mpy
	LSW_ADDRESS_OF(hall_b_filt),				// [0x804]
	LSW_ADDRESS_OF(fdbk1_qep_rev_counting),		// [0x805]	// kpq_low_speed
	LSW_ADDRESS_OF(kiq_low_speed),				// [0x806]
	LSW_ADDRESS_OF(pos_comp_inc),				// [0x807]	// counter_etod motionless_step
	LSW_ADDRESS_OF(final_position),				// [0x808]	//  cos_theta_min
	MSW_ADDRESS_OF(final_position),				// [0x809]
	LSW_ADDRESS_OF(final_angle),				// [0x80a]	// copy_of_nr_a
	LSW_ADDRESS_OF(t_mot),						// [0x80b]
	LSW_ADDRESS_OF(spdref_bq_ini),				// [0x80c]
	LSW_ADDRESS_OF(iqref_bq_ini),				// [0x80d]
	LSW_ADDRESS_OF(electric_pos_long),			// [0x80e]
	MSW_ADDRESS_OF(electric_pos_long),			// [0x80f]
	LSW_ADDRESS_OF(electric_pos_long_th),		// [0x810]
	MSW_ADDRESS_OF(electric_pos_long_th),		// [0x811]
	LSW_ADDRESS_OF(fdbk2_new_position),			// [0x812]
	LSW_ADDRESS_OF(fdbk2_old_position),			// [0x813]
	LSW_ADDRESS_OF(i2t_integral_limit),			// [0x814]
	MSW_ADDRESS_OF(i2t_integral_limit),			// [0x815]
	LSW_ADDRESS_OF(i2t_integral),				// [0x816]
	MSW_ADDRESS_OF(i2t_integral),				// [0x817]
	LSW_ADDRESS_OF(i_i2t_prot),					// [0x818]
	LSW_ADDRESS_OF(sf_i2t),						// [0x819]
	LSW_ADDRESS_OF(master_resolution),			// [0x81a]
	MSW_ADDRESS_OF(master_resolution),			// [0x81b]
	LSW_ADDRESS_OF(pos2),						// [0x81c]
	MSW_ADDRESS_OF(pos2),						// [0x81d]
	LSW_ADDRESS_OF(cap_pos2),					// [0x81e]
	MSW_ADDRESS_OF(cap_pos2),					// [0x81f]
	LSW_ADDRESS_OF(mspd),						// [0x820]
	LSW_ADDRESS_OF(pos2_inc),					// [0x821]
	LSW_ADDRESS_OF(lss_aar),					// [0x822]
	LSW_ADDRESS_OF(lss_active),					// [0x823]
	LSW_ADDRESS_OF(scibr_init),					// [0x824]
	LSW_ADDRESS_OF(tx_buf_free_index),			// [0x825]
	LSW_ADDRESS_OF(eg_correction),				// [0x826]
	MSW_ADDRESS_OF(eg_correction),				// [0x827]
	LSW_ADDRESS_OF(sum_eg_corr),				// [0x828]
	MSW_ADDRESS_OF(sum_eg_corr),				// [0x829]
	LSW_ADDRESS_OF(minc),						// [0x82a]
	MSW_ADDRESS_OF(minc),						// [0x82b]
	LSW_ADDRESS_OF(sinc),						// [0x82c]		|---- ---- ---- ----|---- ---- ---- ----|XXXX XXXX XXXX XXXX|
	(int32_t*)MSB_ADDRESS_OF(sinc),				// [0x82d]		|XXXX XXXX XXXX XXXX|XXXX XXXX XXXX XXXX|---- ---- ---- ----|
	(int16_t*)(MSB_ADDRESS_OF(sinc) + SIZEOF16),// [0x82e]		|XXXX XXXX XXXX XXXX|---- ---- ---- ----|---- ---- ---- ----|
	LSW_ADDRESS_OF(quick_stop_status),			// [0x82f]
	LSW_ADDRESS_OF(t_pi1),						// [0x830]
	MSW_ADDRESS_OF(t_pi1),						// [0x831]
	LSW_ADDRESS_OF(ls_active),					// [0x832]
	LSW_ADDRESS_OF(alpha2),						// [0x833]
	LSW_ADDRESS_OF(apos_rec),					// [0x834]
	MSW_ADDRESS_OF(apos_rec),					// [0x835]
	LSW_ADDRESS_OF(lsn_state),					// [0x836]
	LSW_ADDRESS_OF(lsp_state),					// [0x837]
	LSW_ADDRESS_OF(tpos_old),					// [0x838]
	MSW_ADDRESS_OF(tpos_old),					// [0x839]
	LSW_ADDRESS_OF(y_first),					// [0x83a]
	MSW_ADDRESS_OF(y_first),					// [0x83b]
	LSW_ADDRESS_OF(y_last),						// [0x83c]
	MSW_ADDRESS_OF(y_last),						// [0x83d]
	LSW_ADDRESS_OF(x1_1),						// [0x83e]
	MSW_ADDRESS_OF(x1_1),						// [0x83f]
	LSW_ADDRESS_OF(cam_flag),					// [0x840]
	LSW_ADDRESS_OF(ssi_nr_of_params),			// [0x841]
	LSW_ADDRESS_OF(ssi_type_of_fdbk),			// [0x842]	/* SSI = 1; BiSS = 2*/
	LSW_ADDRESS_OF(fdbk2_bits_st),				// [0x843]
	LSW_ADDRESS_OF(fdbk2_bits_mt),				// [0x844]
	LSW_ADDRESS_OF(fdbk2_is_gray_coded),		// [0x845]
	LSW_ADDRESS_OF(fdbk2_encoder_baudrate),		// [0x846]
	LSW_ADDRESS_OF(offset_pos_delta),			// [0x847]
	LSW_ADDRESS_OF(sin_speed_acq),				// [0x848]
	LSW_ADDRESS_OF(ssi_ccr_ini),				// [0x849]
	LSW_ADDRESS_OF(step_resolution_long),		// [0x84a]
	MSW_ADDRESS_OF(step_resolution_long),		// [0x84b]
	LSW_ADDRESS_OF(encoder_resolution_long),	// [0x84c]
	MSW_ADDRESS_OF(encoder_resolution_long),	// [0x84d]
	LSW_ADDRESS_OF(cos_speed_acq),				// [0x84e]
	LSW_ADDRESS_OF(u_a_ref_bkp),				// [0x84f]
	LSW_ADDRESS_OF(u_b_ref_bkp),				// [0x850]
	LSW_ADDRESS_OF(u_c_ref_bkp),				// [0x851]
	LSW_ADDRESS_OF(linear_hall_3_min),			// [0x852]
	LSW_ADDRESS_OF(linear_hall_3_coeff),		// [0x853]
	LSW_ADDRESS_OF(linear_hall_1_amplitude),	// [0x854]
	LSW_ADDRESS_OF(linear_hall_2_amplitude),	// [0x855]
	LSW_ADDRESS_OF(el_angle_fract),				// [0x856]
	LSW_ADDRESS_OF(upgrade),					// [0x857]	upgrade REGISTER
	LSW_ADDRESS_OF(c_dec),						// [0x858]
	MSW_ADDRESS_OF(c_dec),						// [0x859]
	LSW_ADDRESS_OF(cntrl_mode),					// [0x85a]
	LSW_ADDRESS_OF(write_index),				// [0x85b]
	LSW_ADDRESS_OF(read_index),					// [0x85c]
	LSW_ADDRESS_OF(free_index),					// [0x85d]
	LSW_ADDRESS_OF(first_pvt_point),			// [0x85e]
	LSW_ADDRESS_OF(cyclic_interpolation_active),// [0x85f]
	LSW_ADDRESS_OF(pvt_spd_1),					// [0x860]
	MSW_ADDRESS_OF(pvt_spd_1),					// [0x861]
	LSW_ADDRESS_OF(pvt_intgr_counter),			// [0x862]
	LSW_ADDRESS_OF(pvt_status),					// [0x863]
	LSW_ADDRESS_OF(pvt_buf_st_addr),			// [0x864]
	LSW_ADDRESS_OF(pvt_buf_len),				// [0x865]
	LSW_ADDRESS_OF(pvt_buf_rd),					// [0x866]
	LSW_ADDRESS_OF(pvt_buf_wr),					// [0x867]
	LSW_ADDRESS_OF(pvt_buf_crt_len),			// [0x868]
	LSW_ADDRESS_OF(pvt_setpvt_value),			// [0x869]
	LSW_ADDRESS_OF(pvt_pos0),					// [0x86a]
	MSW_ADDRESS_OF(pvt_pos0),					// [0x86b]
	LSW_ADDRESS_OF(pvt_pos1),					// [0x86c]
	MSW_ADDRESS_OF(pvt_pos1),					// [0x86d]
	LSW_ADDRESS_OF(pvt_n_buf_low),				// [0x86e]
	LSW_ADDRESS_OF(level_ad5),					// [0x86f]
	LSW_ADDRESS_OF(m_ref2),						// [0x870]
	MSW_ADDRESS_OF(m_ref2),						// [0x871]
	LSW_ADDRESS_OF(m_ref_1),					// [0x872]
	MSW_ADDRESS_OF(m_ref_1),					// [0x873]
	LSW_ADDRESS_OF(elpos_long),					// [0x874]
	MSW_ADDRESS_OF(elpos_long),					// [0x875]
	LSW_ADDRESS_OF(e_level_ad5),				// [0x876]
	LSW_ADDRESS_OF(delta_el_pos),				// [0x877]
	LSW_ADDRESS_OF(registration_active),		// [0x878]
	LSW_ADDRESS_OF(spd_err_prot),				// [0x879]
	LSW_ADDRESS_OF(spd_ton_err),				// [0x87a]
	LSW_ADDRESS_OF(i_beta),						// [0x87b]
	LSW_ADDRESS_OF(i2_filtered),				// [0x87c]
	LSW_ADDRESS_OF(adoffset_active),			// [0x87d]
	LSW_ADDRESS_OF(reg_dref),					// [0x87e]
	MSW_ADDRESS_OF(reg_dref),					// [0x87f]
	LSW_ADDRESS_OF(max_presc_val),				// [0x880]
	LSW_ADDRESS_OF(no_pulses),					// [0x881]	// hall_tr1
	LSW_ADDRESS_OF(hall_tr2),					// [0x882]	// hall_tr2
	LSW_ADDRESS_OF(qep_count_init),				// [0x883]
	LSW_ADDRESS_OF(read_pos_value),				// [0x884]
	LSW_ADDRESS_OF(change_spdctrl_lim),			// [0x885]
	LSW_ADDRESS_OF(time_old[0]),				// [0x886]		FIXME: 45/48 array length?
	LSW_ADDRESS_OF(time_old[1]),				// [0x887]
	LSW_ADDRESS_OF(ref_inc),					// [0x888]
	LSW_ADDRESS_OF(neg_mult_res),				// [0x889]
	LSW_ADDRESS_OF(sw_lim_neg),					// [0x88a]
	MSW_ADDRESS_OF(sw_lim_neg),					// [0x88b]
	LSW_ADDRESS_OF(sw_lim_pos),					// [0x88c]
	MSW_ADDRESS_OF(sw_lim_pos),					// [0x88d]
	LSW_ADDRESS_OF(ml_event_mask_2),			// [0x88e]
	LSW_ADDRESS_OF(slave_position),				// [0x88f]
	LSW_ADDRESS_OF(k_omega),					// [0x890]
	LSW_ADDRESS_OF(theta_filtered),				// [0x891]
	LSW_ADDRESS_OF(kp_tht),						// [0x892]
	LSW_ADDRESS_OF(ki_tht),						// [0x893]
	LSW_ADDRESS_OF(sh_p_tht),					// [0x894]
	LSW_ADDRESS_OF(sh_i_tht),					// [0x895]
	LSW_ADDRESS_OF(time_limit),					// [0x896]
	LSW_ADDRESS_OF(i_tht_l),					// [0x897]
	LSW_ADDRESS_OF(i_tht_h),					// [0x898]
	LSW_ADDRESS_OF(theta_tst),					// [0x899]
	LSW_ADDRESS_OF(execute_t_mode),				// [0x89a]
	LSW_ADDRESS_OF(i_q_test),					// [0x89b]
	LSW_ADDRESS_OF(angle_inc),					// [0x89c]
	LSW_ADDRESS_OF(time_elapsed),				// [0x89d]
	LSW_ADDRESS_OF(filt_a),						// [0x89e]
	MSW_ADDRESS_OF(filt_a),						// [0x89f]
	LSW_ADDRESS_OF(filt_b),						// [0x8a0]
	MSW_ADDRESS_OF(filt_b),						// [0x8a1]
	LSW_ADDRESS_OF(master_id2),					// [0x8a2]
	LSW_ADDRESS_OF(move_state),					// [0x8a3]
	LSW_ADDRESS_OF(start_position),				// [0x8a4]
	MSW_ADDRESS_OF(start_position),				// [0x8a5]
	LSW_ADDRESS_OF(first_position),				// [0x8a6]
	MSW_ADDRESS_OF(first_position),				// [0x8a7]
	LSW_ADDRESS_OF(init_angle),					// [0x8a8]
	LSW_ADDRESS_OF(stepper_standby_current),	// [0x8a9]
	LSW_ADDRESS_OF(digin_mask_long),			// [0x8aa]
	MSW_ADDRESS_OF(digin_mask_long),			// [0x8ab]
	LSW_ADDRESS_OF(homing_current),				// [0x8ac]
	LSW_ADDRESS_OF(homing_time),				// [0x8ad]
	LSW_ADDRESS_OF(ena_pin_info),				// [0x8ae]
	LSW_ADDRESS_OF(analogue_reference),			// [0x8af]
	LSW_ADDRESS_OF(dtmin),						// [0x8b0]
	MSW_ADDRESS_OF(dtmin),						// [0x8b1]
	LSW_ADDRESS_OF(dtmax),						// [0x8b2]
	MSW_ADDRESS_OF(dtmax),						// [0x8b3]
	LSW_ADDRESS_OF(speed_scaling_factor),		// [0x8b4]
	MSW_ADDRESS_OF(speed_scaling_factor),		// [0x8b5]
	LSW_ADDRESS_OF(endat_temp2),				// [0x8b6]
	MSW_ADDRESS_OF(endat_temp2),				// [0x8b7]
	LSW_ADDRESS_OF(spd_est),					// [0x8b8]
	LSW_ADDRESS_OF(vm_temp2),					// [0x8b9]
	LSW_ADDRESS_OF(endat_temp),					// [0x8ba]
	LSW_ADDRESS_OF(host_address),				// [0x8bb]
	LSW_ADDRESS_OF(r_shift),					// [0x8bc]
	LSW_ADDRESS_OF(u_ri_scaling),				// [0x8bd]
	LSW_ADDRESS_OF(u_ri_shift),					// [0x8be]
	LSW_ADDRESS_OF(speed_u_ri),					// [0x8bf]
	LSW_ADDRESS_OF(time_lim),					// [0x8c0]
	LSW_ADDRESS_OF(speed_ns),					// [0x8c1]
	LSW_ADDRESS_OF(al_status),					// [0x8c2]
	LSW_ADDRESS_OF(d_i_q),						// [0x8c3]
	LSW_ADDRESS_OF(l_scaling),					// [0x8c4]
	LSW_ADDRESS_OF(l_shift),					// [0x8c5]
	LSW_ADDRESS_OF(spd_err_long),				// [0x8c6]
	MSW_ADDRESS_OF(spd_err_long),				// [0x8c7]
	LSW_ADDRESS_OF(enc_margin),					// [0x8c8]		// theta_hall
	MSW_ADDRESS_OF(enc_margin),					// [0x8c9]		// theta_inc_hall
	LSW_ADDRESS_OF(endat_no_rev),				// [0x8ca]
	LSW_ADDRESS_OF(bldc_sin),					// [0x8cb]
	LSW_ADDRESS_OF(endat_fract),				// [0x8cc]
	LSW_ADDRESS_OF(endat_res),					// [0x8cd]
	LSW_ADDRESS_OF(pos_delta_t),				// [0x8ce]
	LSW_ADDRESS_OF(offset_detect),				// [0x8cf]
	LSW_ADDRESS_OF(debug),						// [0x8d0]
	LSW_ADDRESS_OF(jerk0_int),					// [0x8d1]
	LSW_ADDRESS_OF(time_jerk),					// [0x8d2]
	MSW_ADDRESS_OF(time_jerk),					// [0x8d3]
	LSW_ADDRESS_OF(time_2),						// [0x8d4]
	MSW_ADDRESS_OF(time_2),						// [0x8d5]
	LSW_ADDRESS_OF(time_4),						// [0x8d6]
	MSW_ADDRESS_OF(time_4),						// [0x8d7]
	LSW_ADDRESS_OF(nlines_el_rev),				// [0x8d8]		//nlines_el_rev_or_c_spd_t
	LSW_ADDRESS_OF(cqep2theta),					// [0x8d9]		//cqep2theta_or_sh_c_spd_t
	(double*)&sc_acc,							// [0x8da]
	(double*)&sc_acc,							// [0x8db]
	(double*)&sc_spd,							// [0x8dc]
	(double*)&sc_spd,							// [0x8dd]
	LSW_ADDRESS_OF(c_ref_final),				// [0x8de]
	MSW_ADDRESS_OF(c_ref_final),				// [0x8df]
	LSW_ADDRESS_OF(interpolation_counter),		// [0x8e0]
	MSW_ADDRESS_OF(interpolation_counter),		// [0x8e1]
	LSW_ADDRESS_OF(interpolation_period),		// [0x8e2]
	MSW_ADDRESS_OF(interpolation_period),		// [0x8e3]
	LSW_ADDRESS_OF(jerk_int),					// [0x8e4]
	LSW_ADDRESS_OF(jerk2_int),					// [0x8e5]
	LSW_ADDRESS_OF(c_ref_1),					// [0x8e6]
	MSW_ADDRESS_OF(c_ref_1),					// [0x8e7]
	LSW_ADDRESS_OF(jerk6_fr),					// [0x8e8]
	MSW_ADDRESS_OF(jerk6_fr),					// [0x8e9]
	LSW_ADDRESS_OF(sc_seg_time),				// [0x8ea]
	MSW_ADDRESS_OF(sc_seg_time),				// [0x8eb]
	LSW_ADDRESS_OF(const_1_6),					// [0x8ec]
	MSW_ADDRESS_OF(const_1_6),					// [0x8ed]
	LSW_ADDRESS_OF(sc_c_pos),					// [0x8ee]
	MSW_ADDRESS_OF(sc_c_pos),					// [0x8ef]
	LSW_ADDRESS_OF(jerk6_int),					// [0x8f0]
	LSW_ADDRESS_OF(sincos_oversampling),		// [0x8f1]
	LSW_ADDRESS_OF(linhalls_oversampling),		// [0x8f2]
	LSW_ADDRESS_OF(currents_oversampling),		// [0x8f3]
	LSW_ADDRESS_OF(motor_digital_halls),		// [0x8f4]
	LSW_ADDRESS_OF(adc_trigger_offset),			// [0x8f5]
	LSW_ADDRESS_OF(value_ram),					// [0x8f6]
	LSW_ADDRESS_OF(size_eng),					// [0x8f7]
	LSW_ADDRESS_OF(cmpa),						// [0x8f8]	//checksum_st
	LSW_ADDRESS_OF(cmpb),						// [0x8f9]	//valid_table
	LSW_ADDRESS_OF(cmpc),						// [0x8fa]	//table_sa
	LSW_ADDRESS_OF(cmpd),						// [0x8fb]	//checksum_e2rom
	LSW_ADDRESS_OF(mer),						// [0x8fc]
	LSW_ADDRESS_OF(reg_t_pif),					// [0x8fd]
	LSW_ADDRESS_OF(reg_t_pi),					// [0x8fe]
	MSW_ADDRESS_OF(reg_t_pi),					// [0x8ff]
	LSW_ADDRESS_OF(wd_reset),					// [0x900]
	LSW_ADDRESS_OF(dref_fr),					// [0x901]
	LSW_ADDRESS_OF(cam_input),					// [0x902]
	MSW_ADDRESS_OF(cam_input),					// [0x903]
	LSW_ADDRESS_OF(cam_x_scf),					// [0x904]
	MSW_ADDRESS_OF(cam_x_scf),					// [0x905]
	LSW_ADDRESS_OF(cam_y_scf),					// [0x906]
	MSW_ADDRESS_OF(cam_y_scf),					// [0x907]
	LSW_ADDRESS_OF(digin_status),				// [0x908]
	LSW_ADDRESS_OF(srl_1),						// [0x909]
	LSW_ADDRESS_OF(digin_inversion_mask),		// [0x90a]
	LSW_ADDRESS_OF(digout_inversion_mask),		// [0x90b]
	LSW_ADDRESS_OF(digin_active_level),			// [0x90c]
	LSW_ADDRESS_OF(first_start_bldc),			// [0x90d]
	LSW_ADDRESS_OF(srl),						// [0x90e]
	LSW_ADDRESS_OF(srh),						// [0x90f]
	LSW_ADDRESS_OF(inside_pos_window),			// [0x910]
	LSW_ADDRESS_OF(srh_int),					// [0x911]
	LSW_ADDRESS_OF(acr),						// [0x912]
	LSW_ADDRESS_OF(aar_table),					// [0x913]
	LSW_ADDRESS_OF(flag_tml_instruction),		// [0x914]
	LSW_ADDRESS_OF(sat_val_cmp_ini),			// [0x915]
	LSW_ADDRESS_OF(fdbk2_qep_rev_counting),		// [0x916]
	LSW_ADDRESS_OF(sincos_fract_ld),			// [0x917]
	LSW_ADDRESS_OF(qual_bq2),					// [0x918]
	MSW_ADDRESS_OF(qual_bq2),					// [0x919]
	LSW_ADDRESS_OF(postrigg_1),					// [0x91a]
	MSW_ADDRESS_OF(postrigg_1),					// [0x91b]
	LSW_ADDRESS_OF(postrigg_2),					// [0x91c]
	MSW_ADDRESS_OF(postrigg_2),					// [0x91d]
	LSW_ADDRESS_OF(postrigg_3),					// [0x91e]
	MSW_ADDRESS_OF(postrigg_3),					// [0x91f]
	LSW_ADDRESS_OF(postrigg_4),					// [0x920]
	MSW_ADDRESS_OF(postrigg_4),					// [0x921]
	LSW_ADDRESS_OF(cmpb_inin),					// [0x922]
	LSW_ADDRESS_OF(checksum_eng_for_save),		// [0x923]
	LSW_ADDRESS_OF(table_configuration_id),		// [0x924]
	LSW_ADDRESS_OF(checksum_save),				// [0x925]
	LSW_ADDRESS_OF(enable_off),					// [0x926]
	LSW_ADDRESS_OF(master_id),					// [0x927]
	LSW_ADDRESS_OF(cbr_table),					// [0x928]
	LSW_ADDRESS_OF(flag_msg_send),				// [0x929]
	LSW_ADDRESS_OF(send_ack),					// [0x92a]
	LSW_ADDRESS_OF(disable_send_pvtsts),		// [0x92b]
	LSW_ADDRESS_OF(crt_seg_pvt_spd),			// [0x92c]
	MSW_ADDRESS_OF(crt_seg_pvt_spd),			// [0x92d]
	LSW_ADDRESS_OF(sync_error),					// [0x92e]
	MSW_ADDRESS_OF(sync_error),					// [0x92f]
	LSW_ADDRESS_OF(original_pwm_period),		// [0x930]
	LSW_ADDRESS_OF(sync_margin),				// [0x931]
	LSW_ADDRESS_OF(sync_rate),					// [0x932]
	LSW_ADDRESS_OF(sync_increment),				// [0x933]
	LSW_ADDRESS_OF(master_time),				// [0x934]
	MSW_ADDRESS_OF(master_time),				// [0x935]
	LSW_ADDRESS_OF(master_time_1),				// [0x936]
	MSW_ADDRESS_OF(master_time_1),				// [0x937]
	LSW_ADDRESS_OF(master_offset_time),			// [0x938]
	MSW_ADDRESS_OF(master_offset_time),			// [0x939]
	LSW_ADDRESS_OF(slave_offset_time),			// [0x93a]
	MSW_ADDRESS_OF(slave_offset_time),			// [0x93b]
	LSW_ADDRESS_OF(slave_base_time),			// [0x93c]
	MSW_ADDRESS_OF(slave_base_time),			// [0x93d]
	LSW_ADDRESS_OF(t1pr_old),					// [0x93e]
	LSW_ADDRESS_OF(sync_status),				// [0x93f]
	LSW_ADDRESS_OF(absolute_position_fdbk2),	// [0x940]
	MSW_ADDRESS_OF(absolute_position_fdbk2),	// [0x941]
	LSW_ADDRESS_OF(master_offset_modulo),		// [0x942]
	MSW_ADDRESS_OF(master_offset_modulo),		// [0x943]
	LSW_ADDRESS_OF(rg_sampling),				// [0x944]
	MSW_ADDRESS_OF(rg_sampling),				// [0x945]
	LSW_ADDRESS_OF(t1cnt_buf),					// [0x946]
	LSW_ADDRESS_OF(offset_sync),				// [0x947]
	LSW_ADDRESS_OF(sync_on_fast),				// [0x948]
	LSW_ADDRESS_OF(absolute_time_rem),			// [0x949]
	LSW_ADDRESS_OF(slave_base_time_stop),		// [0x94a]
	MSW_ADDRESS_OF(slave_base_time_stop),		// [0x94b]
	LSW_ADDRESS_OF(axis_absolute_time),			// [0x94c]
	MSW_ADDRESS_OF(axis_absolute_time), 		// [0x94d]
	LSW_ADDRESS_OF(sync_cycle),					// [0x94e]
	MSW_ADDRESS_OF(sync_cycle),					// [0x94f]
	LSW_ADDRESS_OF(ml_time_sync),				// [0x950]
	MSW_ADDRESS_OF(ml_time_sync),				// [0x951]
	LSW_ADDRESS_OF(send_master_offset),			// [0x952]
	LSW_ADDRESS_OF(ki_spd_est),					// [0x953]
	LSW_ADDRESS_OF(master_increment_inst),		// [0x954]
	MSW_ADDRESS_OF(master_increment_inst),		// [0x955]
	LSW_ADDRESS_OF(pos_2theta_filt),			// [0x956]
	MSW_ADDRESS_OF(pos_2theta_filt),			// [0x957]
	LSW_ADDRESS_OF(target_position_1),			// [0x958]
	MSW_ADDRESS_OF(target_position_1),			// [0x959]
	LSW_ADDRESS_OF(target_position_fast),		// [0x95a]
	MSW_ADDRESS_OF(target_position_fast),		// [0x95b]
	LSW_ADDRESS_OF(kp_spd_est),					// [0x95c]
	LSW_ADDRESS_OF(est_spd),					// [0x95d]
	LSW_ADDRESS_OF(int_spd_est),				// [0x95e]
	MSW_ADDRESS_OF(int_spd_est),				// [0x95f]
	LSW_ADDRESS_OF(pos_2theta_p),				// [0x960]
	LSW_ADDRESS_OF(pulse_dir_initialized),		// [0x961]
	LSW_ADDRESS_OF(srlh_mask),					// [0x962]
	LSW_ADDRESS_OF(srh_mask),					// [0x963]
	LSW_ADDRESS_OF(mer_1),						// [0x964]
	LSW_ADDRESS_OF(mer_mask),					// [0x965]
	LSW_ADDRESS_OF(digin_status_1),				// [0x966]
	LSW_ADDRESS_OF(digin_status_mask),			// [0x967]
	LSW_ADDRESS_OF(srh_1),						// [0x968]
	LSW_ADDRESS_OF(k_uphase),					// [0x969]
	LSW_ADDRESS_OF(disable_sol_cor),			// [0x96a]
	LSW_ADDRESS_OF(timeout_reached),			// [0x96b]
	LSW_ADDRESS_OF(wait_time32),				// [0x96c]
	MSW_ADDRESS_OF(wait_time32),				// [0x96d]
	LSW_ADDRESS_OF(apos_monitor),				// [0x96e]
	MSW_ADDRESS_OF(apos_monitor),				// [0x96f]
	LSW_ADDRESS_OF(monitor_speed),				// [0x970]
	MSW_ADDRESS_OF(monitor_speed),				// [0x971]
	LSW_ADDRESS_OF(time_1),						// [0x972]
	MSW_ADDRESS_OF(time_1),						// [0x973]
	LSW_ADDRESS_OF(time_2),						// [0x974]
	MSW_ADDRESS_OF(time_2),						// [0x975]
	LSW_ADDRESS_OF(feedback_error_register),	// [0x976]
	LSW_ADDRESS_OF(skip_can_msg),				// [0x977]
	LSW_ADDRESS_OF(skip_can_msg_value),			// [0x978]
	LSW_ADDRESS_OF(var_i3),						// [0x979]
	LSW_ADDRESS_OF(i2t_integral_drive),			// [0x97a]
	MSW_ADDRESS_OF(i2t_integral_drive),			// [0x97b]
	LSW_ADDRESS_OF(i2t_integral_warning_drive),	// [0x97c]
	LSW_ADDRESS_OF(port_iocr),					// [0x97d]		
	LSW_ADDRESS_OF(interpolation_time_val),		// [0x97e]
	LSW_ADDRESS_OF(interpolation_time_index),	// [0x97f]
	LSW_ADDRESS_OF(i2t_integral_limit_drive),	// [0x980]
	MSW_ADDRESS_OF(i2t_integral_limit_drive),	// [0x981]
	LSW_ADDRESS_OF(i_q_ref_filt_ct),			// [0x982]
	LSW_ADDRESS_OF(tml_int_period),				// [0x983]
	LSW_ADDRESS_OF(ecam_init_pos),				// [0x984]
	MSW_ADDRESS_OF(ecam_init_pos),				// [0x985]
	LSW_ADDRESS_OF(i_i2tprot_drive),			// [0x986]
	LSW_ADDRESS_OF(i_q_ref_filtered),			// [0x987]
	LSW_ADDRESS_OF(apos_mot),					// [0x988]
	MSW_ADDRESS_OF(apos_mot),					// [0x989]
	LSW_ADDRESS_OF(load_speed),					// [0x98a]
	MSW_ADDRESS_OF(load_speed),					// [0x98b]
	LSW_ADDRESS_OF(sf_i2t_drive),				// [0x98c]
	LSW_ADDRESS_OF(v_log),						// [0x98d]		//DC logic supply
	LSW_ADDRESS_OF(i_q_ref_temp),				// [0x98e]
	LSW_ADDRESS_OF(k_spd_err),					// [0x98f]
	LSW_ADDRESS_OF(fdbk1_missing_threshold),		// [0x990]
	LSW_ADDRESS_OF(fdbk2_missing_threshold),		// [0x991]
	LSW_ADDRESS_OF(homepos),					// [0x992]
	MSW_ADDRESS_OF(homepos),					// [0x993]
	LSW_ADDRESS_OF(homespd),					// [0x994]
	MSW_ADDRESS_OF(homespd),					// [0x995]
	LSW_ADDRESS_OF(flag_ping),					// [0x996]
	LSW_ADDRESS_OF(adc_reference_unfiltered),	// [0x997]
	LSW_ADDRESS_OF(execute_autotuning_st_addr),	// [0x998]
	LSW_ADDRESS_OF(adc_10reference_offset),		// [0x999]
	LSW_ADDRESS_OF(adc_10feedback_offset),		// [0x99a]
	LSW_ADDRESS_OF(var_filtered),				// [0x99b]
	LSW_ADDRESS_OF(var_filt_ct),				// [0x99c]
	LSW_ADDRESS_OF(p_plot_var),					// [0x99d]
	LSW_ADDRESS_OF(avg_refhigh_value),			// [0x99e]		XXX free spot NOT USED
	LSW_ADDRESS_OF(checksum_read),				// [0x99f]
	LSW_ADDRESS_OF(checksum_address),			// [0x9a0]
	MSW_ADDRESS_OF(checksum_address),			// [0x9a1]
	LSW_ADDRESS_OF(encoder_type_motor),			// [0x9a2]
	LSW_ADDRESS_OF(encoder_type_load),			// [0x9a3]
	LSW_ADDRESS_OF(encoder_status_fdbk1),		// [0x9a4]
	LSW_ADDRESS_OF(encoder_status_fdbk2),		// [0x9a5]
	LSW_ADDRESS_OF(encoder_command_fdbk1),		// [0x9a6]
	LSW_ADDRESS_OF(encoder_command_fdbk2),		// [0x9a7]
	LSW_ADDRESS_OF(rw_config_register),			// [0x9a8]
	MSW_ADDRESS_OF(rw_config_register),			// [0x9a9]
	LSW_ADDRESS_OF(data_to_write),				// [0x9aa]
	MSW_ADDRESS_OF(data_to_write),				// [0x9ab]
	LSW_ADDRESS_OF(data_to_read),				// [0x9ac]
	MSW_ADDRESS_OF(data_to_read),				// [0x9ad]
	LSW_ADDRESS_OF(write_data_address),			// [0x9ae]
	MSW_ADDRESS_OF(write_data_address),			// [0x9af]
	LSW_ADDRESS_OF(tml_fct),					// [0x9b0]
	LSW_ADDRESS_OF(x6040_control_word),			// [0x9b1]		// former control_word
	LSW_ADDRESS_OF(x6040_control_word_1),		// [0x9b2]
	LSW_ADDRESS_OF(tml_tr),						// [0x9b3]		XXX free spot NOT USED
	LSW_ADDRESS_OF(modes_of_operation),			// [0x9b4]
	LSW_ADDRESS_OF(modes_of_operation_display),	// [0x9b5]
	LSW_ADDRESS_OF(current_scale_type),			// [0x9b6]
	LSW_ADDRESS_OF(homing_nr),					// [0x9b7]
	LSW_ADDRESS_OF(digout_status),				// [0x9b8]
	LSW_ADDRESS_OF(select_can_mode),			// [0x9b9]
	LSW_ADDRESS_OF(pos_err_long),				// [0x9ba]
	MSW_ADDRESS_OF(pos_err_long),				// [0x9bb]
	LSW_ADDRESS_OF(motion_profile_type),		// [0x9bc]
	LSW_ADDRESS_OF(cam_e2rom_load_address),		// [0x9bd]
	LSW_ADDRESS_OF(non_compare_event_ctrl),		// [0x9be]		XXX free spot NOT USED
	LSW_ADDRESS_OF(execute_main_tml),			// [0x9bf]
	LSW_ADDRESS_OF(init_tables_p),				// [0x9c0]
	LSW_ADDRESS_OF(start_address_h),			// [0x9c1]
	LSW_ADDRESS_OF(tml_sw_ver),					// [0x9c2]
	MSW_ADDRESS_OF(tml_sw_ver),					// [0x9c3]
	LSW_ADDRESS_OF(copy_of_digin_status),		// [0x9c4]
	LSW_ADDRESS_OF(copy_of_mer),				// [0x9c5]
	LSW_ADDRESS_OF(status_ds402_2),				// [0x9c6]
	LSW_ADDRESS_OF(cop_1s_timer),				// [0x9c7]
	LSW_ADDRESS_OF(start_address_tr),			// [0x9c8]
	LSW_ADDRESS_OF(start_address_fct),			// [0x9c9]
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9ca]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9cb]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9cc]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9cd]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9ce]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9cf]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d0]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d1]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d2]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d3]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d4]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d5]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d6]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d7]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d8]		XXX free spot NOT USED
	LSW_ADDRESS_OF(null_padding_variable),		// [0x9d9]		XXX free spot NOT USED
	LSW_ADDRESS_OF(real_c_pos),					// [0x9da]
	MSW_ADDRESS_OF(real_c_pos),					// [0x9db]
	LSW_ADDRESS_OF(adc_feedback),				// [0x9dc]
	LSW_ADDRESS_OF(ad2_filt_ct),				// [0x9dd]
	LSW_ADDRESS_OF(aspd_bq_ini),				// [0x9de]
	MSW_ADDRESS_OF(null_padding_variable),		// [0x9df]		XXX free spot
	LSW_ADDRESS_OF(err_prot_long),				// [0x9e0]
	MSW_ADDRESS_OF(err_prot_long),				// [0x9e1]
	LSW_ADDRESS_OF(real_pos),					// [0x9e2]
	MSW_ADDRESS_OF(real_pos),					// [0x9e3]
	LSW_ADDRESS_OF(status_ds402),				// [0x9e4]
	LSW_ADDRESS_OF(monitor_new_position),		// [0x9e5]
	MSW_ADDRESS_OF(monitor_new_position),		// [0x9e6]
	LSW_ADDRESS_OF(interpolation_submode_select),// [0x9e7]
	LSW_ADDRESS_OF(status_ds402_1),				// [0x9e8]
	LSW_ADDRESS_OF(special_ios_position),		// [0x9e9]		XXX free spot NOT USED
	LSW_ADDRESS_OF(target_c_spd),				// [0x9ea]
	MSW_ADDRESS_OF(target_c_spd),				// [0x9eb]
	LSW_ADDRESS_OF(flag_stop_pvt_pt),			// [0x9ec]
	LSW_ADDRESS_OF(adc_linear_hall_3),			// [0x9ed]
	LSW_ADDRESS_OF(srh_srl),					// [0x9ee]
	MSW_ADDRESS_OF(srh_srl),					// [0x9ef]
	LSW_ADDRESS_OF(comm_error_option_code),		// [0x9f0]
	LSW_ADDRESS_OF(fault_reaction_option_code),	// [0x9f1]
	LSW_ADDRESS_OF(real_c_dec),					// [0x9f2]
	MSW_ADDRESS_OF(real_c_dec),					// [0x9f3]
	LSW_ADDRESS_OF(at_ref_index),				// [0x9f4]
	LSW_ADDRESS_OF(atr),						// [0x9f5]
	LSW_ADDRESS_OF(at_ref_start_addr),			// [0x9f6]
	LSW_ADDRESS_OF(at_ref_max_points),			// [0x9f7]
	LSW_ADDRESS_OF(sto_hw_err_timeout),			// [0x9f8]
	LSW_ADDRESS_OF(brake_apply_delay),			// [0x9f9]
	LSW_ADDRESS_OF(brake_release_delay),		// [0x9fa]
	LSW_ADDRESS_OF(apply_torque),				// [0x9fb]
	LSW_ADDRESS_OF(err_min_fc),					// [0x9fc]
	LSW_ADDRESS_OF(ton_err_min_fc),				// [0x9fd]
	LSW_ADDRESS_OF(contor_err_min_fc),			// [0x9fe]
	LSW_ADDRESS_OF(fdbk2_powerup_timeout)		// [0x9ff]
};



/*************************************************************************
*	MC5 MEMORY PAGE @ A000h
*************************************************************************/
void *p_tml_data_pga000[TML_DATA_TABLE_SIZE_PGA000] __attribute__ ((aligned (4))) =
{
		LSW_ADDRESS_OF(min_pos_range),				// [0xA000]	//AF00
		MSW_ADDRESS_OF(min_pos_range),				// [0xA001]
		LSW_ADDRESS_OF(max_pos_range),				// [0xA002]
		MSW_ADDRESS_OF(max_pos_range),				// [0xA003]
		LSW_ADDRESS_OF(pos_range_defined),			// [0xA004]
		LSW_ADDRESS_OF(pos_opt_code),				// [0xA005]
		LSW_ADDRESS_OF(fdbk2_bits_ign_st),			// [0xA006]
		LSW_ADDRESS_OF(fdbk2_bits_ign_mt),			// [0xA007]
		LSW_ADDRESS_OF(target_position_4_plot),		// [0xA008]
		MSW_ADDRESS_OF(target_position_4_plot),		// [0xA009]
		LSW_ADDRESS_OF(polarity),					// [0xA00A]
		LSW_ADDRESS_OF(linear_hall_3_raw),			// [0xA00B]
		LSW_ADDRESS_OF(device_identity.firmware_name),	// [0xA00C]
		MSW_ADDRESS_OF(device_identity.firmware_name),	// [0xA00D]
		LSW_ADDRESS_OF(serial_number),				// [0xA00E]
		MSW_ADDRESS_OF(serial_number),				// [0xA00F]
		LSW_ADDRESS_OF(bq_mask),					// [0xA010]
		LSW_ADDRESS_OF(new_int_sat),				// [0xA011]
		LSW_ADDRESS_OF(sin_offset),					// [0xA012]
		LSW_ADDRESS_OF(cos_offset),					// [0xA013]
		LSW_ADDRESS_OF(sin_gain),					// [0xA014]
		LSW_ADDRESS_OF(cos_gain),					// [0xA015]
		LSW_ADDRESS_OF(sineps),						// [0xA016]
		LSW_ADDRESS_OF(coseps),						// [0xA017]
		LSW_ADDRESS_OF(flag_filt),					// [0xA018]
		LSW_ADDRESS_OF(encpulses_limit),			// [0xA019]
		LSW_ADDRESS_OF(a1_spd_est_bq_f),			// [0xA01A]
		MSW_ADDRESS_OF(a1_spd_est_bq_f),			// [0xA01B]
		LSW_ADDRESS_OF(a2_spd_est_bq_f),			// [0xA01C]
		MSW_ADDRESS_OF(a2_spd_est_bq_f),			// [0xA01D]
		LSW_ADDRESS_OF(b0_spd_est_bq_f),			// [0xA01E]
		MSW_ADDRESS_OF(b0_spd_est_bq_f),			// [0xA01F]
		LSW_ADDRESS_OF(b1_spd_est_bq_f),			// [0xA020]
		MSW_ADDRESS_OF(b1_spd_est_bq_f),			// [0xA021]
		LSW_ADDRESS_OF(b2_spd_est_bq_f),			// [0xA022]
		MSW_ADDRESS_OF(b2_spd_est_bq_f),			// [0xA023]
		LSW_ADDRESS_OF(rev_spd_ampl),				// [0xA024]
		LSW_ADDRESS_OF(white_noise),				// [0xA025]
		LSW_ADDRESS_OF(i_q_ref_slow),				// [0xA026]
		LSW_ADDRESS_OF(pos_err_abs_val),			// [0xA027]
		LSW_ADDRESS_OF(biss_small_timeout),			// [0xA028]
		LSW_ADDRESS_OF(new_impl_pos_ssi),			// [0xA029]
		LSW_ADDRESS_OF(spd_bdac_min),				// [0xA02A]
		MSW_ADDRESS_OF(spd_bdac_min),				// [0xA02B]
		LSW_ADDRESS_OF(spd_bdac_max),				// [0xA02C]
		MSW_ADDRESS_OF(spd_bdac_max),				// [0xA02D]
		LSW_ADDRESS_OF(pos_hall_off_temp),			// [0xA02E]
		LSW_ADDRESS_OF(gs_index_ct),				// [0xA02F] //AF2F
		LSW_ADDRESS_OF(gs_index_filt),				// [0xA030]
		LSW_ADDRESS_OF(gs_index_no_filt),			// [0xA031]
		LSW_ADDRESS_OF(pos_bldc),					// [0xA032]
		MSW_ADDRESS_OF(pos_bldc),					// [0xA033]
		LSW_ADDRESS_OF(spdsinacqslow_corrected),	// [0xA034]
		LSW_ADDRESS_OF(spdcosacqslow_corrected),	// [0xA035]
		LSW_ADDRESS_OF(coeff_d_pos),				// [0xA036]
		LSW_ADDRESS_OF(max_spd_dualuse),			// [0xA037]
		LSW_ADDRESS_OF(hall_max_spd_dualuse),		// [0xA038]
		LSW_ADDRESS_OF(high_spd_loop_counter),		// [0xA039]
		LSW_ADDRESS_OF(high_Spd_limit),				// [0xA03A]
		MSW_ADDRESS_OF(high_Spd_limit),				// [0xA03B]
		LSW_ADDRESS_OF(low_Spd_limit),				// [0xA03C]
		MSW_ADDRESS_OF(low_Spd_limit),				// [0xA03D]
		LSW_ADDRESS_OF(low_spd_loop_counter),		// [0xA03E]
		LSW_ADDRESS_OF(special_ios_status),			// [0xA03F]	//AF3F
		LSW_ADDRESS_OF(gs_index),					// [0xA040]	//B7C0
		LSW_ADDRESS_OF(gs_index_1),					// [0xA041]
		LSW_ADDRESS_OF(gs_counter),					// [0xA042]
		LSW_ADDRESS_OF(gs_crt_addr),				// [0xA043]
		LSW_ADDRESS_OF(p_gs_param),					// [0xA044]
		MSW_ADDRESS_OF(p_gs_param),					// [0xA045]
		LSW_ADDRESS_OF(p_gs_data),					// [0xA046]
		MSW_ADDRESS_OF(p_gs_data),					// [0xA047]
		LSW_ADDRESS_OF(p_gs_table),					// [0xA048]
		MSW_ADDRESS_OF(p_gs_table),					// [0xA049]
		LSW_ADDRESS_OF(gs_error),					// [0xA04A]
		LSW_ADDRESS_OF(gs_best_settling_type),		// [0xA04B]
		LSW_ADDRESS_OF(gs_speed),					// [0xA04C]
		MSW_ADDRESS_OF(gs_speed),					// [0xA04D]
		LSW_ADDRESS_OF(p_gs_trig),					// [0xA04E]
		MSW_ADDRESS_OF(p_gs_trig),					// [0xA04F]
		LSW_ADDRESS_OF(gs_i_min),					// [0xA050]
		LSW_ADDRESS_OF(gs_i_max),					// [0xA051]
		LSW_ADDRESS_OF(gs_value_1),					// [0xA052]
		MSW_ADDRESS_OF(gs_value_1),					// [0xA053]
		LSW_ADDRESS_OF(gs_steps),					// [0xA054]
		LSW_ADDRESS_OF(gs_man_1),					// [0xA055]
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA056]
		LSW_ADDRESS_OF(gs_trig_addr),				// [0xA057]
		LSW_ADDRESS_OF(gs_trig_value),				// [0xA058]
		MSW_ADDRESS_OF(gs_trig_value),				// [0xA059]
		LSW_ADDRESS_OF(gs_trig_value_1),			// [0xA05A]
		MSW_ADDRESS_OF(gs_trig_value_1),			// [0xA05B]
		LSW_ADDRESS_OF(gs_k_poserr),				// [0xA05C]
		LSW_ADDRESS_OF(cam_offset),					// [0xA05D]
		MSW_ADDRESS_OF(cam_offset),					// [0xA05E]
		LSW_ADDRESS_OF(real_tonimax),				// [0xA05F]
		LSW_ADDRESS_OF(gs_start_addr),				// [0xA060]
		LSW_ADDRESS_OF(gs_max_elem),				// [0xA061]
		LSW_ADDRESS_OF(gs_words),					// [0xA062]
		LSW_ADDRESS_OF(gs_type),					// [0xA063]
		LSW_ADDRESS_OF(gs_man),						// [0xA064]
		LSW_ADDRESS_OF(gs_time),					// [0xA065]
		LSW_ADDRESS_OF(gs_param[0]),						// [0xA066]
		LSW_ADDRESS_OF(gs_param[1]),						// [0xA067]
		LSW_ADDRESS_OF(gs_param[2]),						// [0xA068]
		LSW_ADDRESS_OF(gs_param[3]),						// [0xA069]
		LSW_ADDRESS_OF(gs_param[4]),						// [0xA06A]
		LSW_ADDRESS_OF(gs_param[5]),						// [0xA06B]
		LSW_ADDRESS_OF(gs_param[6]),						// [0xA06C]
		LSW_ADDRESS_OF(gs_param[7]),						// [0xA06D]
		LSW_ADDRESS_OF(gs_param[8]),						// [0xA06E]
		LSW_ADDRESS_OF(gs_param[9]),						// [0xA06F]
		LSW_ADDRESS_OF(gs_param[10]),						// [0xA070]
		LSW_ADDRESS_OF(gs_param[11]),						// [0xA071]
		LSW_ADDRESS_OF(gs_param[12]),						// [0xA072]
		LSW_ADDRESS_OF(gs_param[13]),						// [0xA073]
		LSW_ADDRESS_OF(gs_param[14]),						// [0xA074]
		LSW_ADDRESS_OF(gs_param[15]),						// [0xA075]
		LSW_ADDRESS_OF(gs_param[16]),						// [0xA076]
		LSW_ADDRESS_OF(gs_param[17]),						// [0xA077]
		LSW_ADDRESS_OF(gs_param[18]),						// [0xA078]
		LSW_ADDRESS_OF(gs_param[19]),						// [0xA079]
		LSW_ADDRESS_OF(gs_param[20]),						// [0xA07A]
		LSW_ADDRESS_OF(gs_param[21]),						// [0xA07B]
		LSW_ADDRESS_OF(gs_param[22]),						// [0xA07C]
		LSW_ADDRESS_OF(gs_param[23]),						// [0xA07D]
		LSW_ADDRESS_OF(gs_param[24]),						// [0xA07E]
		LSW_ADDRESS_OF(gs_param[25]),						// [0xA07F]	//B7FF
		LSW_ADDRESS_OF(dtheta0),					// [0xA080]	//BE80
		MSW_ADDRESS_OF(dtheta0),					// [0xA081]
		LSW_ADDRESS_OF(dtheta_inc),					// [0xA082]
		MSW_ADDRESS_OF(dtheta_inc),					// [0xA083]
		LSW_ADDRESS_OF(ampl0),						// [0xA084]
		MSW_ADDRESS_OF(ampl0),						// [0xA085]
		LSW_ADDRESS_OF(ampl_inc),					// [0xA086]
		MSW_ADDRESS_OF(ampl_inc),					// [0xA087]
		LSW_ADDRESS_OF(sin_n),						// [0xA088]
		MSW_ADDRESS_OF(sin_n),						// [0xA089]
		LSW_ADDRESS_OF(phase0),						// [0xA08A]
		LSW_ADDRESS_OF(first_sine),					// [0xA08B]
		LSW_ADDRESS_OF(sin_angle),					// [0xA08C]
		MSW_ADDRESS_OF(sin_angle),					// [0xA08D]
		LSW_ADDRESS_OF(sin_angle_inc),				// [0xA08E]
		MSW_ADDRESS_OF(sin_angle_inc),				// [0xA08F]
		LSW_ADDRESS_OF(sine_wave),					// [0xA090]
		MSW_ADDRESS_OF(sine_wave),					// [0xA091]
		LSW_ADDRESS_OF(sin_cntr),					// [0xA092]
		MSW_ADDRESS_OF(sin_cntr),					// [0xA093]
		LSW_ADDRESS_OF(sin_a),						// [0xA094]
		MSW_ADDRESS_OF(sin_a),						// [0xA095]
		LSW_ADDRESS_OF(sine_wave_1),				// [0xA096]
		MSW_ADDRESS_OF(sine_wave_1),				// [0xA097]
		LSW_ADDRESS_OF(sin_n_rg),					// [0xA098]
		MSW_ADDRESS_OF(sin_n_rg),					// [0xA099]
		LSW_ADDRESS_OF(ampl_sat),					// [0xA09A]
		MSW_ADDRESS_OF(ampl_sat),					// [0xA09B]
		LSW_ADDRESS_OF(dtheta_inc_sat),				// [0xA09C]
		MSW_ADDRESS_OF(dtheta_inc_sat),				// [0xA09D]
		LSW_ADDRESS_OF(sin_a_sat),					// [0xA09E]
		MSW_ADDRESS_OF(sin_a_sat),					// [0xA09F]
		LSW_ADDRESS_OF(sin_angle_inc_sat),			// [0xA0A0]
		MSW_ADDRESS_OF(sin_angle_inc_sat),			// [0xA0A1]
		LSW_ADDRESS_OF(sin_angle_inc_rg),			// [0xA0A2]
		MSW_ADDRESS_OF(sin_angle_inc_rg),			// [0xA0A3]
		LSW_ADDRESS_OF(sin_a_inc),					// [0xA0A4]
		MSW_ADDRESS_OF(sin_a_inc),					// [0xA0A5]	//BEA5
		LSW_ADDRESS_OF(bq_f_coeff[0].a1),			// [0xA0A6]	//BF00
		MSW_ADDRESS_OF(bq_f_coeff[0].a1),			// [0xA0A7]
		LSW_ADDRESS_OF(bq_f_coeff[0].a2),			// [0xA0A8]
		MSW_ADDRESS_OF(bq_f_coeff[0].a2),			// [0xA0A9]
		LSW_ADDRESS_OF(bq_f_coeff[0].b0),			// [0xA0AA]
		MSW_ADDRESS_OF(bq_f_coeff[0].b0),			// [0xA0AB]
		LSW_ADDRESS_OF(bq_f_coeff[0].b1),			// [0xA0AC]
		MSW_ADDRESS_OF(bq_f_coeff[0].b1),			// [0xA0AD]
		LSW_ADDRESS_OF(bq_f_coeff[0].b2),			// [0xA0AE]
		MSW_ADDRESS_OF(bq_f_coeff[0].b2),			// [0xA0AF]
		LSW_ADDRESS_OF(bq_f_coeff[0].gain),			// [0xA0B0]
		MSW_ADDRESS_OF(bq_f_coeff[0].gain),			// [0xA0B1]
		LSW_ADDRESS_OF(bq_f_coeff[1].a1),			// [0xA0B2]
		MSW_ADDRESS_OF(bq_f_coeff[1].a1),			// [0xA0B3]
		LSW_ADDRESS_OF(bq_f_coeff[1].a2),			// [0xA0B4]
		MSW_ADDRESS_OF(bq_f_coeff[1].a2),			// [0xA0B5]
		LSW_ADDRESS_OF(bq_f_coeff[1].b0),			// [0xA0B6]
		MSW_ADDRESS_OF(bq_f_coeff[1].b0),			// [0xA0B7]
		LSW_ADDRESS_OF(bq_f_coeff[1].b1),			// [0xA0B8]
		MSW_ADDRESS_OF(bq_f_coeff[1].b1),			// [0xA0B9]
		LSW_ADDRESS_OF(bq_f_coeff[1].b2),			// [0xA0BA]
		MSW_ADDRESS_OF(bq_f_coeff[1].b2),			// [0xA0BB]
		LSW_ADDRESS_OF(bq_f_coeff[1].gain),			// [0xA0BC]
		MSW_ADDRESS_OF(bq_f_coeff[1].gain),			// [0xA0BD]
		LSW_ADDRESS_OF(bq_f_coeff[2].a1),			// [0xA0BE]
		MSW_ADDRESS_OF(bq_f_coeff[2].a1),			// [0xA0BF]
		LSW_ADDRESS_OF(bq_f_coeff[2].a2),			// [0xA0C0]
		MSW_ADDRESS_OF(bq_f_coeff[2].a2),			// [0xA0C1]
		LSW_ADDRESS_OF(bq_f_coeff[2].b0),			// [0xA0C2]
		MSW_ADDRESS_OF(bq_f_coeff[2].b0),			// [0xA0C3]
		LSW_ADDRESS_OF(bq_f_coeff[2].b1),			// [0xA0C4]
		MSW_ADDRESS_OF(bq_f_coeff[2].b1),			// [0xA0C5]
		LSW_ADDRESS_OF(bq_f_coeff[2].b2),			// [0xA0C6]
		MSW_ADDRESS_OF(bq_f_coeff[2].b2),			// [0xA0C7]
		LSW_ADDRESS_OF(bq_f_coeff[2].gain),			// [0xA0C8]
		MSW_ADDRESS_OF(bq_f_coeff[2].gain),			// [0xA0C9]
		LSW_ADDRESS_OF(bq_f_coeff[3].a1),			// [0xA0CA]
		MSW_ADDRESS_OF(bq_f_coeff[3].a1),			// [0xA0CB]
		LSW_ADDRESS_OF(bq_f_coeff[3].a2),			// [0xA0CC]
		MSW_ADDRESS_OF(bq_f_coeff[3].a2),			// [0xA0CD]
		LSW_ADDRESS_OF(bq_f_coeff[3].b0),			// [0xA0CE]
		MSW_ADDRESS_OF(bq_f_coeff[3].b0),			// [0xA0CF]
		LSW_ADDRESS_OF(bq_f_coeff[3].b1),			// [0xA0D0]
		MSW_ADDRESS_OF(bq_f_coeff[3].b1),			// [0xA0D1]
		LSW_ADDRESS_OF(bq_f_coeff[3].b2),			// [0xA0D2]
		MSW_ADDRESS_OF(bq_f_coeff[3].b2),			// [0xA0D3]
		LSW_ADDRESS_OF(bq_f_coeff[3].gain),			// [0xA0D4]
		MSW_ADDRESS_OF(bq_f_coeff[3].gain),			// [0xA0D5]
		LSW_ADDRESS_OF(bq_f_coeff[4].a1),			// [0xA0D6]
		MSW_ADDRESS_OF(bq_f_coeff[4].a1),			// [0xA0D7]
		LSW_ADDRESS_OF(bq_f_coeff[4].a2),			// [0xA0D8]
		MSW_ADDRESS_OF(bq_f_coeff[4].a2),			// [0xA0D9]
		LSW_ADDRESS_OF(bq_f_coeff[4].b0),			// [0xA0DA]
		MSW_ADDRESS_OF(bq_f_coeff[4].b0),			// [0xA0DB]
		LSW_ADDRESS_OF(bq_f_coeff[4].b1),			// [0xA0DC]
		MSW_ADDRESS_OF(bq_f_coeff[4].b1),			// [0xA0DD]
		LSW_ADDRESS_OF(bq_f_coeff[4].b2),			// [0xA0DE]
		MSW_ADDRESS_OF(bq_f_coeff[4].b2),			// [0xA0DF]
		LSW_ADDRESS_OF(bq_f_coeff[4].gain),			// [0xA0E0]
		MSW_ADDRESS_OF(bq_f_coeff[4].gain),			// [0xA0E1]
		LSW_ADDRESS_OF(bq_f_coeff[5].a1),			// [0xA0E2]
		MSW_ADDRESS_OF(bq_f_coeff[5].a1),			// [0xA0E3]
		LSW_ADDRESS_OF(bq_f_coeff[5].a2),			// [0xA0E4]
		MSW_ADDRESS_OF(bq_f_coeff[5].a2),			// [0xA0E5]
		LSW_ADDRESS_OF(bq_f_coeff[5].b0),			// [0xA0E6]
		MSW_ADDRESS_OF(bq_f_coeff[5].b0),			// [0xA0E7]
		LSW_ADDRESS_OF(bq_f_coeff[5].b1),			// [0xA0E8]
		MSW_ADDRESS_OF(bq_f_coeff[5].b1),			// [0xA0E9]
		LSW_ADDRESS_OF(bq_f_coeff[5].b2),			// [0xA0EA]
		MSW_ADDRESS_OF(bq_f_coeff[5].b2),			// [0xA0EB]
		LSW_ADDRESS_OF(bq_f_coeff[5].gain),			// [0xA0EC]
		MSW_ADDRESS_OF(bq_f_coeff[5].gain),			// [0xA0ED]
		LSW_ADDRESS_OF(bq_f_coeff[6].a1),			// [0xA0EE]
		MSW_ADDRESS_OF(bq_f_coeff[6].a1),			// [0xA0EF]
		LSW_ADDRESS_OF(bq_f_coeff[6].a2),			// [0xA0F0]
		MSW_ADDRESS_OF(bq_f_coeff[6].a2),			// [0xA0F1]
		LSW_ADDRESS_OF(bq_f_coeff[6].b0),			// [0xA0F2]
		MSW_ADDRESS_OF(bq_f_coeff[6].b0),			// [0xA0F3]
		LSW_ADDRESS_OF(bq_f_coeff[6].b1),			// [0xA0F4]
		MSW_ADDRESS_OF(bq_f_coeff[6].b1),			// [0xA0F5]
		LSW_ADDRESS_OF(bq_f_coeff[6].b2),			// [0xA0F6]
		MSW_ADDRESS_OF(bq_f_coeff[6].b2),			// [0xA0F7]
		LSW_ADDRESS_OF(bq_f_coeff[6].gain),			// [0xA0F8]
		MSW_ADDRESS_OF(bq_f_coeff[6].gain),			// [0xA0F9]
		LSW_ADDRESS_OF(bq_f_coeff[7].a1),			// [0xA0FA]
		MSW_ADDRESS_OF(bq_f_coeff[7].a1),			// [0xA0FB]
		LSW_ADDRESS_OF(bq_f_coeff[7].a2),			// [0xA0FC]
		MSW_ADDRESS_OF(bq_f_coeff[7].a2),			// [0xA0FD]
		LSW_ADDRESS_OF(bq_f_coeff[7].b0),			// [0xA0FE]
		MSW_ADDRESS_OF(bq_f_coeff[7].b0),			// [0xA0FF]
		LSW_ADDRESS_OF(bq_f_coeff[7].b1),			// [0xA100]
		MSW_ADDRESS_OF(bq_f_coeff[7].b1),			// [0xA101]
		LSW_ADDRESS_OF(bq_f_coeff[7].b2),			// [0xA102]
		MSW_ADDRESS_OF(bq_f_coeff[7].b2),			// [0xA103]
		LSW_ADDRESS_OF(bq_f_coeff[7].gain),			// [0xA104]
		MSW_ADDRESS_OF(bq_f_coeff[7].gain),			// [0xA105]
		LSW_ADDRESS_OF(bq_f_coeff[8].a1),			// [0xA106]
		MSW_ADDRESS_OF(bq_f_coeff[8].a1),			// [0xA107]
		LSW_ADDRESS_OF(bq_f_coeff[8].a2),			// [0xA108]
		MSW_ADDRESS_OF(bq_f_coeff[8].a2),			// [0xA109]
		LSW_ADDRESS_OF(bq_f_coeff[8].b0),			// [0xA10A]
		MSW_ADDRESS_OF(bq_f_coeff[8].b0),			// [0xA10B]
		LSW_ADDRESS_OF(bq_f_coeff[8].b1),			// [0xA10C]
		MSW_ADDRESS_OF(bq_f_coeff[8].b1),			// [0xA10D]
		LSW_ADDRESS_OF(bq_f_coeff[8].b2),			// [0xA10E]
		MSW_ADDRESS_OF(bq_f_coeff[8].b2),			// [0xA10F]
		LSW_ADDRESS_OF(bq_f_coeff[8].gain),			// [0xA110]
		MSW_ADDRESS_OF(bq_f_coeff[8].gain),			// [0xA111]
		LSW_ADDRESS_OF(bq_f_coeff[9].a1),			// [0xA112]
		MSW_ADDRESS_OF(bq_f_coeff[9].a1),			// [0xA113]
		LSW_ADDRESS_OF(bq_f_coeff[9].a2),			// [0xA114]
		MSW_ADDRESS_OF(bq_f_coeff[9].a2),			// [0xA115]
		LSW_ADDRESS_OF(bq_f_coeff[9].b0),			// [0xA116]
		MSW_ADDRESS_OF(bq_f_coeff[9].b0),			// [0xA117]
		LSW_ADDRESS_OF(bq_f_coeff[9].b1),			// [0xA118]
		MSW_ADDRESS_OF(bq_f_coeff[9].b1),			// [0xA119]
		LSW_ADDRESS_OF(bq_f_coeff[9].b2),			// [0xA11A]
		MSW_ADDRESS_OF(bq_f_coeff[9].b2),			// [0xA11B]
		LSW_ADDRESS_OF(bq_f_coeff[9].gain),			// [0xA11C]
		MSW_ADDRESS_OF(bq_f_coeff[9].gain),			// [0xA11D]
		LSW_ADDRESS_OF(l_user_var1),				// [0xA11E]
		MSW_ADDRESS_OF(l_user_var1),				// [0xA11F]
		LSW_ADDRESS_OF(l_user_var2),				// [0xA120]
		MSW_ADDRESS_OF(l_user_var2),				// [0xA121]
		LSW_ADDRESS_OF(l_user_var3),				// [0xA122]
		MSW_ADDRESS_OF(l_user_var3),				// [0xA123]
		LSW_ADDRESS_OF(l_user_var4),				// [0xA124]
		MSW_ADDRESS_OF(l_user_var4),				// [0xA125]
		LSW_ADDRESS_OF(touch_probe_1_pos_edge),		// [0xA126]
		MSW_ADDRESS_OF(touch_probe_1_pos_edge),		// [0xA127]
		LSW_ADDRESS_OF(touch_probe_1_neg_edge),		// [0xA128]
		MSW_ADDRESS_OF(touch_probe_1_neg_edge),		// [0xA129]
		LSW_ADDRESS_OF(touch_probe_2_pos_edge),		// [0xA12A]
		MSW_ADDRESS_OF(touch_probe_2_pos_edge),		// [0xA12B]
		LSW_ADDRESS_OF(touch_probe_2_neg_edge),		// [0xA12C]
		MSW_ADDRESS_OF(touch_probe_2_neg_edge),		// [0xA12D]
		LSW_ADDRESS_OF(capture_configuration),		// [0xA12E]
		LSW_ADDRESS_OF(capture_status),				// [0xA12F]
		LSW_ADDRESS_OF(configreg_sync),				// [0xA130]
		LSW_ADDRESS_OF(real_t_pos),					// [0xA131]
		MSW_ADDRESS_OF(real_t_pos),					// [0xA132]
		LSW_ADDRESS_OF(real_err_prot),				// [0xA133]
		MSW_ADDRESS_OF(real_err_prot),				// [0xA134]
		LSW_ADDRESS_OF(buffer_clear),				// [0xA135]
		LSW_ADDRESS_OF(real_c_spd),					// [0xA136]
		MSW_ADDRESS_OF(real_c_spd),					// [0xA137]
		LSW_ADDRESS_OF(digin_status_ds402),			// [0xA138]
		MSW_ADDRESS_OF(digin_status_ds402),			// [0xA139]
		LSW_ADDRESS_OF(device_identity.hardware_id),// [0xA13A]
		LSW_ADDRESS_OF(disable_sol_cor),				// [0xA13B]
		LSW_ADDRESS_OF(outputs_config_buffer.first),	// [0xA13C]
		MSW_ADDRESS_OF(outputs_config_buffer.first),	// [0xA13D]
		LSW_ADDRESS_OF(outputs_config_buffer.second),	// [0xA13E]
		MSW_ADDRESS_OF(outputs_config_buffer.second),	// [0xA13F]
		LSW_ADDRESS_OF(io_register[0]),				// [0xA140]
		MSW_ADDRESS_OF(io_register[0]),				// [0xA141]
		LSW_ADDRESS_OF(io_register[1]),				// [0xA142]
		MSW_ADDRESS_OF(io_register[1]),				// [0xA143]
		LSW_ADDRESS_OF(io_register[2]),				// [0xA144]
		MSW_ADDRESS_OF(io_register[2]),				// [0xA145]
		LSW_ADDRESS_OF(io_register[3]),				// [0xA146]
		MSW_ADDRESS_OF(io_register[3]),				// [0xA147]
		LSW_ADDRESS_OF(io_register[4]),				// [0xA148]
		MSW_ADDRESS_OF(io_register[4]),				// [0xA149]
		LSW_ADDRESS_OF(io_register[5]),				// [0xA14A]
		MSW_ADDRESS_OF(io_register[5]),				// [0xA14B]
		LSW_ADDRESS_OF(io_register[6]),				// [0xA14C]
		MSW_ADDRESS_OF(io_register[6]),				// [0xA14D]
		LSW_ADDRESS_OF(io_register[7]),				// [0xA14E]
		MSW_ADDRESS_OF(io_register[7]),				// [0xA14F]
		LSW_ADDRESS_OF(io_register[8]),				// [0xA150]
		MSW_ADDRESS_OF(io_register[8]),				// [0xA151]
		LSW_ADDRESS_OF(io_register[9]),				// [0xA152]
		MSW_ADDRESS_OF(io_register[9]),				// [0xA153]
		LSW_ADDRESS_OF(io_register[10]),			// [0xA154]
		MSW_ADDRESS_OF(io_register[10]),			// [0xA155]
		LSW_ADDRESS_OF(io_register[11]),			// [0xA156]
		MSW_ADDRESS_OF(io_register[11]),			// [0xA157]
		LSW_ADDRESS_OF(io_register[12]),			// [0xA158]
		MSW_ADDRESS_OF(io_register[12]),			// [0xA159]
		LSW_ADDRESS_OF(io_register[13]),			// [0xA15A]
		MSW_ADDRESS_OF(io_register[13]),			// [0xA15B]
		LSW_ADDRESS_OF(io_register[14]),			// [0xA15C]
		MSW_ADDRESS_OF(io_register[14]),			// [0xA15D]
		LSW_ADDRESS_OF(io_register[15]),			// [0xA15E]
		MSW_ADDRESS_OF(io_register[15]),			// [0xA15F]
		LSW_ADDRESS_OF(io_register[16]),			// [0xA160]
		MSW_ADDRESS_OF(io_register[16]),			// [0xA161]
		LSW_ADDRESS_OF(io_register[17]),			// [0xA162]
		MSW_ADDRESS_OF(io_register[17]),			// [0xA163]
		LSW_ADDRESS_OF(io_register[18]),			// [0xA164]
		MSW_ADDRESS_OF(io_register[18]),			// [0xA165]
		LSW_ADDRESS_OF(io_register[19]),			// [0xA166]
		MSW_ADDRESS_OF(io_register[19]),			// [0xA167]
		LSW_ADDRESS_OF(io_register[20]),			// [0xA168]
		MSW_ADDRESS_OF(io_register[20]),			// [0xA169]
		LSW_ADDRESS_OF(io_register[21]),			// [0xA16A]
		MSW_ADDRESS_OF(io_register[21]),			// [0xA16B]
		LSW_ADDRESS_OF(io_register[22]),			// [0xA16C]
		MSW_ADDRESS_OF(io_register[22]),			// [0xA16D]
		LSW_ADDRESS_OF(io_register[23]),			// [0xA16E]
		MSW_ADDRESS_OF(io_register[23]),			// [0xA16F]
		LSW_ADDRESS_OF(io_register[24]),			// [0xA170]
		MSW_ADDRESS_OF(io_register[24]),			// [0xA171]
		LSW_ADDRESS_OF(io_register[25]),			// [0xA172]
		MSW_ADDRESS_OF(io_register[25]),			// [0xA173]
		LSW_ADDRESS_OF(io_register[26]),			// [0xA174]
		MSW_ADDRESS_OF(io_register[26]),			// [0xA175]
		LSW_ADDRESS_OF(io_register[27]),			// [0xA176]
		MSW_ADDRESS_OF(io_register[27]),			// [0xA177]
		LSW_ADDRESS_OF(io_register[28]),			// [0xA178]
		MSW_ADDRESS_OF(io_register[28]),			// [0xA179]
		LSW_ADDRESS_OF(io_register[29]),			// [0xA17A]
		MSW_ADDRESS_OF(io_register[29]),			// [0xA17B]
		LSW_ADDRESS_OF(io_register[30]),			// [0xA17C]
		MSW_ADDRESS_OF(io_register[30]),			// [0xA17D]
		LSW_ADDRESS_OF(io_register[31]),			// [0xA17E]
		MSW_ADDRESS_OF(io_register[31]),			// [0xA17F]
		LSW_ADDRESS_OF(io_register[32]),			// [0xA180]
		MSW_ADDRESS_OF(io_register[32]),			// [0xA181]
		LSW_ADDRESS_OF(io_register[33]),			// [0xA182]
		MSW_ADDRESS_OF(io_register[33]),			// [0xA183]
		LSW_ADDRESS_OF(io_register[34]),			// [0xA184]
		MSW_ADDRESS_OF(io_register[34]),			// [0xA185]
		LSW_ADDRESS_OF(io_register[35]),			// [0xA186]
		MSW_ADDRESS_OF(io_register[35]),			// [0xA187]
		LSW_ADDRESS_OF(io_register[36]),			// [0xA188]
		MSW_ADDRESS_OF(io_register[36]),			// [0xA189]
		LSW_ADDRESS_OF(io_register[37]),			// [0xA18A]
		MSW_ADDRESS_OF(io_register[37]),			// [0xA18B]
		LSW_ADDRESS_OF(io_register[38]),			// [0xA18C]
		MSW_ADDRESS_OF(io_register[38]),			// [0xA18D]
		LSW_ADDRESS_OF(io_register[39]),			// [0xA18E]
		MSW_ADDRESS_OF(io_register[39]),			// [0xA18F]
		LSW_ADDRESS_OF(io_register[40]),			// [0xA190]
		MSW_ADDRESS_OF(io_register[40]),			// [0xA191]
		LSW_ADDRESS_OF(io_register[41]),			// [0xA192]
		MSW_ADDRESS_OF(io_register[41]),			// [0xA193]
		LSW_ADDRESS_OF(io_register[42]),			// [0xA194]
		MSW_ADDRESS_OF(io_register[42]),			// [0xA195]
		LSW_ADDRESS_OF(io_register[43]),			// [0xA196]
		MSW_ADDRESS_OF(io_register[43]),			// [0xA197]
		LSW_ADDRESS_OF(io_register[44]),			// [0xA198]
		MSW_ADDRESS_OF(io_register[44]),			// [0xA199]
		LSW_ADDRESS_OF(io_register[45]),			// [0xA19A]
		MSW_ADDRESS_OF(io_register[45]),			// [0xA19B]
		LSW_ADDRESS_OF(io_register[46]),			// [0xA19C]
		MSW_ADDRESS_OF(io_register[46]),			// [0xA19D]
		LSW_ADDRESS_OF(io_register[47]),			// [0xA19E]
		MSW_ADDRESS_OF(io_register[47]),			// [0xA19F]
		LSW_ADDRESS_OF(io_register[48]),			// [0xA1A0]
		MSW_ADDRESS_OF(io_register[48]),			// [0xA1A1]
		LSW_ADDRESS_OF(io_register[49]),			// [0xA1A2]
		MSW_ADDRESS_OF(io_register[49]),			// [0xA1A3]
		LSW_ADDRESS_OF(io_register[50]),			// [0xA1A4]
		MSW_ADDRESS_OF(io_register[50]),			// [0xA1A5]
		LSW_ADDRESS_OF(io_register[51]),			// [0xA1A6]
		MSW_ADDRESS_OF(io_register[51]),			// [0xA1A7]
		LSW_ADDRESS_OF(io_register[52]),			// [0xA1A8]
		MSW_ADDRESS_OF(io_register[52]),			// [0xA1A9]
		LSW_ADDRESS_OF(io_register[53]),			// [0xA1AA]
		MSW_ADDRESS_OF(io_register[53]),			// [0xA1AB]
		LSW_ADDRESS_OF(io_register[54]),			// [0xA1AC]
		MSW_ADDRESS_OF(io_register[54]),			// [0xA1AD]
		LSW_ADDRESS_OF(io_register[55]),			// [0xA1AE]
		MSW_ADDRESS_OF(io_register[55]),			// [0xA1AF]
		LSW_ADDRESS_OF(io_register[56]),			// [0xA1B0]
		MSW_ADDRESS_OF(io_register[56]),			// [0xA1B1]
		LSW_ADDRESS_OF(io_register[57]),			// [0xA1B2]
		MSW_ADDRESS_OF(io_register[57]),			// [0xA1B3]
		LSW_ADDRESS_OF(io_register[58]),			// [0xA1B4]
		MSW_ADDRESS_OF(io_register[58]),			// [0xA1B5]
		LSW_ADDRESS_OF(io_register[59]),			// [0xA1B6]
		MSW_ADDRESS_OF(io_register[59]),			// [0xA1B7]
		LSW_ADDRESS_OF(io_register[60]),			// [0xA1B8]
		MSW_ADDRESS_OF(io_register[60]),			// [0xA1B9]
		LSW_ADDRESS_OF(io_register[61]),			// [0xA1BA]
		MSW_ADDRESS_OF(io_register[61]),			// [0xA1BB]
		LSW_ADDRESS_OF(io_register[62]),			// [0xA1BC]
		MSW_ADDRESS_OF(io_register[62]),			// [0xA1BD]
		LSW_ADDRESS_OF(io_register[63]),			// [0xA1BE]
		MSW_ADDRESS_OF(io_register[63]),			// [0xA1BF]
		LSW_ADDRESS_OF(ioregister_inputs_offset),	// [0xA1C0]
		LSW_ADDRESS_OF(ioregister_outputs_offset),	// [0xA1C1]
		LSW_ADDRESS_OF(sw_file_download),			// [0xA1C2]
		LSW_ADDRESS_OF(adc_current_ia_gain_f),		// [0xA1C3]
		MSW_ADDRESS_OF(adc_current_ia_gain_f),		// [0xA1C4]
		LSW_ADDRESS_OF(adc_current_ia_offset),		// [0xA1C5]
		LSW_ADDRESS_OF(adc_current_ib_gain_f),		// [0xA1C6]
		MSW_ADDRESS_OF(adc_current_ib_gain_f),		// [0xA1C7]
		LSW_ADDRESS_OF(adc_current_ib_offset),		// [0xA1C8]
		LSW_ADDRESS_OF(adc_current_ic_gain_f),		// [0xA1C9]
		MSW_ADDRESS_OF(adc_current_ic_gain_f),		// [0xA1CA]
		LSW_ADDRESS_OF(adc_current_ic_offset),		// [0xA1CB]
		LSW_ADDRESS_OF(adc_current_id_gain_f),		// [0xA1CC]
		MSW_ADDRESS_OF(adc_current_id_gain_f),		// [0xA1CD]
		LSW_ADDRESS_OF(adc_current_id_offset),		// [0xA1CE]
		LSW_ADDRESS_OF(adc_linear_hall_1_gain_f),	// [0xA1CF]
		MSW_ADDRESS_OF(adc_linear_hall_1_gain_f),	// [0xA1D0]
		LSW_ADDRESS_OF(adc_linear_hall_1_offset),	// [0xA1D1]
		LSW_ADDRESS_OF(adc_linear_hall_2_gain_f),	// [0xA1D2]
		MSW_ADDRESS_OF(adc_linear_hall_2_gain_f),	// [0xA1D3]
		LSW_ADDRESS_OF(adc_linear_hall_2_offset),	// [0xA1D4]
		LSW_ADDRESS_OF(adc_linear_hall_3_gain_f),	// [0xA1D5]
		MSW_ADDRESS_OF(adc_linear_hall_3_gain_f),	// [0xA1D6]
		LSW_ADDRESS_OF(adc_linear_hall_3_offset),	// [0xA1D7]
		LSW_ADDRESS_OF(adc_encoder_sin_gain_f),		// [0xA1D8]
		MSW_ADDRESS_OF(adc_encoder_sin_gain_f),		// [0xA1D9]
		LSW_ADDRESS_OF(adc_encoder_sin_offset),		// [0xA1DA]
		LSW_ADDRESS_OF(adc_encoder_cos_gain_f),		// [0xA1DB]
		MSW_ADDRESS_OF(adc_encoder_cos_gain_f),		// [0xA1DC]
		LSW_ADDRESS_OF(adc_encoder_cos_offset),		// [0xA1DD]
		LSW_ADDRESS_OF(adc_reference_gain_f),		// [0xA1DE]
		MSW_ADDRESS_OF(adc_reference_gain_f),		// [0xA1DF]
		LSW_ADDRESS_OF(adc_reference_offset),		// [0xA1E0]
		LSW_ADDRESS_OF(adc_feedback_gain_f),		// [0xA1E1]
		MSW_ADDRESS_OF(adc_feedback_gain_f),		// [0xA1E2]
		LSW_ADDRESS_OF(adc_feedback_offset),		// [0xA1E3]
		LSW_ADDRESS_OF(adc_v_log_gain_f),			// [0xA1E4]
		MSW_ADDRESS_OF(adc_v_log_gain_f),			// [0xA1E5]
		LSW_ADDRESS_OF(adc_v_log_offset),			// [0xA1E6]
		LSW_ADDRESS_OF(adc_v_mot_gain_f),			// [0xA1E7]
		MSW_ADDRESS_OF(adc_v_mot_gain_f),			// [0xA1E8]
		LSW_ADDRESS_OF(adc_v_mot_offset),			// [0xA1E9]
		LSW_ADDRESS_OF(adc_t_drive_gain_f),			// [0xA1EA]
		MSW_ADDRESS_OF(adc_t_drive_gain_f),			// [0xA1EB]
		LSW_ADDRESS_OF(adc_t_drive_offset),			// [0xA1EC]
		LSW_ADDRESS_OF(adc_t_mot_gain_f),			// [0xA1ED]
		MSW_ADDRESS_OF(adc_t_mot_gain_f),			// [0xA1EE]
		LSW_ADDRESS_OF(adc_t_mot_offset),			// [0xA1EF]
		LSW_ADDRESS_OF(adc_sto_gain_f),				// [0xA1F0]
		MSW_ADDRESS_OF(adc_sto_gain_f),				// [0xA1F1]
		LSW_ADDRESS_OF(adc_sto_offset),				// [0xA1F2]
		LSW_ADDRESS_OF(adc_current_ia_satmax),		// [0xA1F3]
		LSW_ADDRESS_OF(adc_current_ia_satmin),		// [0xA1F4]
		LSW_ADDRESS_OF(adc_current_ib_satmax),		// [0xA1F5]
		LSW_ADDRESS_OF(adc_current_ib_satmin),		// [0xA1F6]
		LSW_ADDRESS_OF(adc_current_ic_satmax),		// [0xA1F7]
		LSW_ADDRESS_OF(adc_current_ic_satmin),		// [0xA1F8]
		LSW_ADDRESS_OF(adc_current_id_satmax),		// [0xA1F9]
		LSW_ADDRESS_OF(adc_current_id_satmin),		// [0xA1FA]
		LSW_ADDRESS_OF(adc_linear_hall_1_satmax),	// [0xA1FB]
		LSW_ADDRESS_OF(adc_linear_hall_1_satmin),	// [0xA1FC]
		LSW_ADDRESS_OF(adc_linear_hall_2_satmax),	// [0xA1FD]
		LSW_ADDRESS_OF(adc_linear_hall_2_satmin),	// [0xA1FE]
		LSW_ADDRESS_OF(adc_linear_hall_3_satmax),	// [0xA1FF]
		LSW_ADDRESS_OF(adc_linear_hall_3_satmin),	// [0xA200]
		LSW_ADDRESS_OF(adc_encoder_sin_satmax),		// [0xA201]
		LSW_ADDRESS_OF(adc_encoder_sin_satmin),		// [0xA202]
		LSW_ADDRESS_OF(adc_encoder_cos_satmax),		// [0xA203]
		LSW_ADDRESS_OF(adc_encoder_cos_satmin),		// [0xA204]
		LSW_ADDRESS_OF(adc_reference_satmax),		// [0xA205]
		LSW_ADDRESS_OF(adc_reference_satmin),		// [0xA206]
		LSW_ADDRESS_OF(adc_feedback_satmax),		// [0xA207]
		LSW_ADDRESS_OF(adc_feedback_satmin),		// [0xA208]
		LSW_ADDRESS_OF(adc_v_log_satmax),			// [0xA209]
		LSW_ADDRESS_OF(adc_v_log_satmin),			// [0xA20A]
		LSW_ADDRESS_OF(adc_v_mot_satmax),			// [0xA20B]
		LSW_ADDRESS_OF(adc_v_mot_satmin),			// [0xA20C]
		LSW_ADDRESS_OF(adc_t_drive_satmax),			// [0xA20D]
		LSW_ADDRESS_OF(adc_t_drive_satmin),			// [0xA20E]
		LSW_ADDRESS_OF(adc_t_mot_satmax),			// [0xA20F]
		LSW_ADDRESS_OF(adc_t_mot_satmin),			// [0xA210]
		LSW_ADDRESS_OF(adc_sto_satmax),				// [0xA211]
		LSW_ADDRESS_OF(adc_sto_satmin),				// [0xA212]
		LSW_ADDRESS_OF(adc_used_shunts),			// [0xA213]
		LSW_ADDRESS_OF(alpha_sincos),				// [0xA214]
		LSW_ADDRESS_OF(linear_hall_1_filtered),		// [0xA215]
		LSW_ADDRESS_OF(linear_hall_2_filtered),		// [0xA216]
		LSW_ADDRESS_OF(linear_hall_3_filtered),		// [0xA217]
		LSW_ADDRESS_OF(linear_hall_2_min),			// [0xA218]
		LSW_ADDRESS_OF(linear_hall_3_max),			// [0xA219]
		LSW_ADDRESS_OF(linear_hall_3_amplitude),	// [0xA21A]
		LSW_ADDRESS_OF(linear_hall_1_coeff),		// [0xA21B]
		LSW_ADDRESS_OF(linear_hall_2_coeff),		// [0xA21C]
		LSW_ADDRESS_OF(offset_lh1),					// [0xA21D]
		LSW_ADDRESS_OF(offset_lh2),					// [0xA21E]
		LSW_ADDRESS_OF(offset_lh3),					// [0xA21F]
		LSW_ADDRESS_OF(lin_hall_amplitude_copy),	// [0xA220]
		LSW_ADDRESS_OF(adc_linear_hall_1),			// [0xA221]
		LSW_ADDRESS_OF(adc_linear_hall_2),			// [0xA222]
		LSW_ADDRESS_OF(linear_hall_sine),			// [0xA223]
		LSW_ADDRESS_OF(linear_hall_cosine),			// [0xA224]
		LSW_ADDRESS_OF(c_acc_decrease),				// [0xA225]
		LSW_ADDRESS_OF(c_spd_decrease),				// [0xA226]
		LSW_ADDRESS_OF(speed_ffwd_output),			// [0xA227]
		MSW_ADDRESS_OF(speed_ffwd_output),			// [0xA228]
		LSW_ADDRESS_OF(debug_1),					// [0xA229]
		LSW_ADDRESS_OF(debug_2),					// [0xA22A]
		LSW_ADDRESS_OF(debug_3),					// [0xA22B]
		LSW_ADDRESS_OF(debug_4),					// [0xA22C]
		LSW_ADDRESS_OF(debug_5),					// [0xA22D]
		LSW_ADDRESS_OF(debug_6),					// [0xA22E]
		LSW_ADDRESS_OF(debug_7),					// [0xA22F]
		LSW_ADDRESS_OF(debug_8),					// [0xA230]
		LSW_ADDRESS_OF(debug_9),					// [0xA231]
		LSW_ADDRESS_OF(acceleration_ffwd_output),	// [0xA232]
		LSW_ADDRESS_OF(kp_crt_f),					// [0xA233]
		MSW_ADDRESS_OF(kp_crt_f),					// [0xA234]
		LSW_ADDRESS_OF(ki_crt_f),					// [0xA235]
		MSW_ADDRESS_OF(ki_crt_f),					// [0xA236]
		LSW_ADDRESS_OF(kp_spd_f),					// [0xA237]
		MSW_ADDRESS_OF(kp_spd_f),					// [0xA238]
		LSW_ADDRESS_OF(ki_spd_f),					// [0xA239]
		MSW_ADDRESS_OF(ki_spd_f),					// [0xA23A]
		LSW_ADDRESS_OF(kp_pos_f),					// [0xA23B]
		MSW_ADDRESS_OF(kp_pos_f),					// [0xA23C]
		LSW_ADDRESS_OF(ki_pos_f),					// [0xA23D]
		MSW_ADDRESS_OF(ki_pos_f),					// [0xA23E]
		LSW_ADDRESS_OF(kd_pos_f),					// [0xA23F]
		MSW_ADDRESS_OF(kd_pos_f),					// [0xA240]
		LSW_ADDRESS_OF(kdf_pos_f),					// [0xA241]
		MSW_ADDRESS_OF(kdf_pos_f),					// [0xA242]
		LSW_ADDRESS_OF(kff_spd_f),					// [0xA243]
		MSW_ADDRESS_OF(kff_spd_f),					// [0xA244]
		LSW_ADDRESS_OF(kff_acc_f),					// [0xA245]
		MSW_ADDRESS_OF(kff_acc_f),					// [0xA246]
		LSW_ADDRESS_OF(kff_load_f),					// [0xA247]
		MSW_ADDRESS_OF(kff_load_f),					// [0xA248]
		LSW_ADDRESS_OF(kp_tht_f),					// [0xA249]
		MSW_ADDRESS_OF(kp_tht_f),					// [0xA24A]
		LSW_ADDRESS_OF(ki_tht_f),					// [0xA24B]
		MSW_ADDRESS_OF(ki_tht_f),					// [0xA24C]
		LSW_ADDRESS_OF(sat_out_crtq_f),				// [0xA24D]
		MSW_ADDRESS_OF(sat_out_crtq_f),				// [0xA24E]
		LSW_ADDRESS_OF(sat_out_crtd_f),				// [0xA24F]
		MSW_ADDRESS_OF(sat_out_crtd_f),				// [0xA250]
		LSW_ADDRESS_OF(sat_out_spd_f),				// [0xA251]
		MSW_ADDRESS_OF(sat_out_spd_f),				// [0xA252]
		LSW_ADDRESS_OF(sat_int_spd_f),				// [0xA253]
		MSW_ADDRESS_OF(sat_int_spd_f),				// [0xA254]
		LSW_ADDRESS_OF(sat_out_pos_f),				// [0xA255]
		MSW_ADDRESS_OF(sat_out_pos_f),				// [0xA256]
		LSW_ADDRESS_OF(sat_int_pos_f),				// [0xA257]
		MSW_ADDRESS_OF(sat_int_pos_f),				// [0xA258]
		LSW_ADDRESS_OF(motor_delta_theta_position),	// [0xA259]
		MSW_ADDRESS_OF(motor_delta_theta_position),	// [0xA25A]
		LSW_ADDRESS_OF(linear_hall_amplitude),		// [0xA25B]
		MSW_ADDRESS_OF(linear_hall_amplitude),		// [0xA25C]
		LSW_ADDRESS_OF(hall_filter_coef),			// [0xA25D]
		LSW_ADDRESS_OF(dma_failsafe_time_window),	// [0xA25E]
		LSW_ADDRESS_OF(adc_sto_level),				// [0xA25F]
		LSW_ADDRESS_OF(boot0_version),				// [0xA260]
		MSW_ADDRESS_OF(boot0_version),				// [0xA261]
		LSW_ADDRESS_OF(boot1_version),				// [0xA262]
		MSW_ADDRESS_OF(boot1_version),				// [0xA263]
		LSW_ADDRESS_OF(asr3),						// [0xA264]
		LSW_ADDRESS_OF(write_active),				// [0xA265]
		LSW_ADDRESS_OF(phy_address),				// [0xA266]
		LSW_ADDRESS_OF(phy_reg_address),			// [0xA267]
		LSW_ADDRESS_OF(phy_command),				// [0xA268]
		LSW_ADDRESS_OF(phy_data),					// [0xA269]
		LSW_ADDRESS_OF(command_error),				// [0xA26A]
		LSW_ADDRESS_OF(read_register),				// [0xA26B]
		LSW_ADDRESS_OF(register_offset),			// [0xA26C]
		LSW_ADDRESS_OF(register_value),				// [0xA26D]
		MSW_ADDRESS_OF(register_value),				// [0xA26E]
		LSW_ADDRESS_OF(feed_constant.divisor),		// [0xA26F]
		MSW_ADDRESS_OF(feed_constant.divisor),		// [0xA270]
		LSW_ADDRESS_OF(gear_ratio.numerator),		// [0xA271]
		MSW_ADDRESS_OF(gear_ratio.numerator),		// [0xA272]
		LSW_ADDRESS_OF(gear_ratio.divisor),			// [0xA273]
		MSW_ADDRESS_OF(gear_ratio.divisor),			// [0xA274]
		LSW_ADDRESS_OF(si_unit_position),			// [0xA275]
		MSW_ADDRESS_OF(si_unit_position),			// [0xA276]
		LSW_ADDRESS_OF(si_unit_velocity),			// [0xA277]
		MSW_ADDRESS_OF(si_unit_velocity),			// [0xA278]
		LSW_ADDRESS_OF(si_unit_acceleration),		// [0xA279]
		MSW_ADDRESS_OF(si_unit_acceleration),		// [0xA27A]
		LSW_ADDRESS_OF(si_unit_jerk),				// [0xA27B]
		MSW_ADDRESS_OF(si_unit_jerk),				// [0xA27C]
		LSW_ADDRESS_OF(velocity_encoder.numerator),	// [0xA27D]
		MSW_ADDRESS_OF(velocity_encoder.numerator),	// [0xA27E]
		LSW_ADDRESS_OF(velocity_encoder.divisor),	// [0xA27F]
		MSW_ADDRESS_OF(velocity_encoder.divisor),	// [0xA280]
		LSW_ADDRESS_OF(acceleration_scaling.numerator),	// [0xA281]
		MSW_ADDRESS_OF(acceleration_scaling.numerator),	// [0xA282]
		LSW_ADDRESS_OF(acceleration_scaling.divisor),// [0xA283]
		MSW_ADDRESS_OF(acceleration_scaling.divisor),// [0xA284]
		LSW_ADDRESS_OF(jerk_factor.numerator),		// [0xA285]
		MSW_ADDRESS_OF(jerk_factor.numerator),		// [0xA286]
		LSW_ADDRESS_OF(jerk_factor.divisor),		// [0xA287]
		MSW_ADDRESS_OF(jerk_factor.divisor),		// [0xA288]
		LSW_ADDRESS_OF(jerk_scaling.numerator),		// [0xA289]
		MSW_ADDRESS_OF(jerk_scaling.numerator),		// [0xA28A]
		LSW_ADDRESS_OF(jerk_scaling.divisor),		// [0xA28B]
		MSW_ADDRESS_OF(jerk_scaling.divisor),		// [0xA28C]
		LSW_ADDRESS_OF(config_buffer),				// [0xA28D]
		LSW_ADDRESS_OF(pt_time),					// [0xA28E]
		LSW_ADDRESS_OF(dummy_object),				// [0xA28F]
		LSW_ADDRESS_OF(overposition_trig_output),	// [0xA290]
		LSW_ADDRESS_OF(aux_capture_configuration),	// [0xA291]
		LSW_ADDRESS_OF(aux_capture_pos_edge),		// [0xA292]
		MSW_ADDRESS_OF(aux_capture_pos_edge),		// [0xA293]
		LSW_ADDRESS_OF(aux_capture_neg_edge),		// [0xA294]
		MSW_ADDRESS_OF(aux_capture_neg_edge),		// [0xA295]
		LSW_ADDRESS_OF(a_mac_address[0]),			// [0xA296]
		LSW_ADDRESS_OF(a_mac_address[2]),			// [0xA297]
		LSW_ADDRESS_OF(a_mac_address[4]),			// [0xA298]
		LSW_ADDRESS_OF(a_ip_address),				// [0xA299]
		MSW_ADDRESS_OF(a_ip_address),				// [0xA29A]
		LSW_ADDRESS_OF(a_sub_net_mask),				// [0xA29B]
		MSW_ADDRESS_OF(a_sub_net_mask),				// [0xA29C]
		LSW_ADDRESS_OF(a_default_gateway),			// [0xA29D]
		MSW_ADDRESS_OF(a_default_gateway),			// [0xA29E]
		LSW_ADDRESS_OF(quickstop_option_code),		// [0xA29F]
		LSW_ADDRESS_OF(shutdown_option_code),		// [0xA2A0]
		LSW_ADDRESS_OF(disable_op_option_code),		// [0xA2A1]
		LSW_ADDRESS_OF(halt_op_oc),					// [0xA2A2]
		LSW_ADDRESS_OF(velocity_treshold),			// [0xA2A3]
		LSW_ADDRESS_OF(target_torque),				// [0xA2A4]
		LSW_ADDRESS_OF(interpolation_data_buffer.first),	// [0xA2A5]
		MSW_ADDRESS_OF(interpolation_data_buffer.first),	// [0xA2A6]
		LSW_ADDRESS_OF(interpolation_data_buffer.second),	// [0xA2A7]
		MSW_ADDRESS_OF(interpolation_data_buffer.second),	// [0xA2A8]
		LSW_ADDRESS_OF(power_stage_command),		// [0xA2A9]
		LSW_ADDRESS_OF(power_stage_register_address),// [0xA2AA]
		LSW_ADDRESS_OF(power_stage_register_data),	// [0xA2AB]
		LSW_ADDRESS_OF(power_stage_received_data),	// [0xA2AC]
		LSW_ADDRESS_OF(power_stage_pdpint_data),	// [0xA2AD]
		MSW_ADDRESS_OF(power_stage_pdpint_data),	// [0xA2AE]
		LSW_ADDRESS_OF(xml_access_from_tml),		// [0xA2AF]
		LSW_ADDRESS_OF(biss_crc_fdbk1_fdbk2),		// [0xA2B0]
		LSW_ADDRESS_OF(autorun_active),				// [0xA2B1]
		LSW_ADDRESS_OF(gpio_read_command),			// [0xA2B2]
		LSW_ADDRESS_OF(port0_input),				// [0xA2B3]
		LSW_ADDRESS_OF(port1_input),				// [0xA2B4]
		LSW_ADDRESS_OF(port2_input),				// [0xA2B5]
		LSW_ADDRESS_OF(port3_input),				// [0xA2B6]
		LSW_ADDRESS_OF(port4_input),				// [0xA2B7]
		LSW_ADDRESS_OF(port5_input),				// [0xA2B8]
		LSW_ADDRESS_OF(port6_input),				// [0xA2B9]
		LSW_ADDRESS_OF(port7_input),				// [0xA2BA]
		LSW_ADDRESS_OF(port8_input),				// [0xA2BB]
		LSW_ADDRESS_OF(port9_input),				// [0xA2BC]
		LSW_ADDRESS_OF(port14_input),				// [0xA2BD]
		LSW_ADDRESS_OF(port15_input),				// [0xA2BE]
		LSW_ADDRESS_OF(gpio_write_command),				// [0xA2BF]
		LSW_ADDRESS_OF(gpio_port_defined),			// [0xA2C0]
		LSW_ADDRESS_OF(gpio_pin_defined),			// [0xA2C1]
		LSW_ADDRESS_OF(gpio_state),					// [0xA2C2]
		LSW_ADDRESS_OF(tml_priority),				// [0xA2C3]
		LSW_ADDRESS_OF(e2rom_store_start_address),	// [0xA2C4]
		LSW_ADDRESS_OF(transaction_jitter_compensation),				// [0xA2C5]
		LSW_ADDRESS_OF(biss_driver_fdbk2.number_of_rx_transactions),	// [0xA2C6]
		LSW_ADDRESS_OF(leading_null_words),			// [0xA2C7]
		LSW_ADDRESS_OF(biss_dma_rx_fdbk2[0]),		// [0xA2C8]
		MSW_ADDRESS_OF(biss_dma_rx_fdbk2[0]),		// [0xA2C9]
		LSW_ADDRESS_OF(biss_dma_rx_fdbk2[4]),		// [0xA2CA]
		MSW_ADDRESS_OF(biss_dma_rx_fdbk2[4]),		// [0xA2CB]
		LSW_ADDRESS_OF(biss_dma_rx_fdbk2[8]),		// [0xA2CC]
		MSW_ADDRESS_OF(biss_dma_rx_fdbk2[8]),		// [0xA2CD]
		LSW_ADDRESS_OF(biss_dma_rx_fdbk2[12]),		// [0xA2CE]
		MSW_ADDRESS_OF(biss_dma_rx_fdbk2[12]),		// [0xA2CF]		
		LSW_ADDRESS_OF(first_ack_clocks),			// [0xA2D0]
		LSW_ADDRESS_OF(adc_10reference_gain_f),		// [0xA2D1]
		MSW_ADDRESS_OF(adc_10reference_gain_f),		// [0xA2D2]
		LSW_ADDRESS_OF(adc_10feedback_gain_f),		// [0xA2D3]
		MSW_ADDRESS_OF(adc_10feedback_gain_f),		// [0xA2D4]
		LSW_ADDRESS_OF(device_name[0]),				// [0xA2D5]
		MSW_ADDRESS_OF(device_name[0]),				// [0xA2D6]
		LSW_ADDRESS_OF(device_name[1]),				// [0xA2D7]
		MSW_ADDRESS_OF(device_name[1]),				// [0xA2D8]
		LSW_ADDRESS_OF(device_name[2]),				// [0xA2D9]
		MSW_ADDRESS_OF(device_name[2]),				// [0xA2DA]
		LSW_ADDRESS_OF(device_name[3]),				// [0xA2DB]
		MSW_ADDRESS_OF(device_name[3]),				// [0xA2DC]
		LSW_ADDRESS_OF(sync_filter_min),			// [0xA2DD]
		LSW_ADDRESS_OF(sync_filter_max),			// [0xA2DE]
		LSW_ADDRESS_OF(ram_value),					// [0xA2DF]
		MSW_ADDRESS_OF(ram_value),					// [0xA2E0]
		LSW_ADDRESS_OF(cpu_reset_reason),   		// [0xA2E1]
		LSW_ADDRESS_OF(id_ipart_f),					// [0xA2E2]
		MSW_ADDRESS_OF(id_ipart_f),					// [0xA2E3]
		LSW_ADDRESS_OF(iq_ipart_f),					// [0xA2E4]
		MSW_ADDRESS_OF(iq_ipart_f),					// [0xA2E5]
		LSW_ADDRESS_OF(speed_ipart_f),				// [0xA2E6]
		MSW_ADDRESS_OF(speed_ipart_f),				// [0xA2E7]
		LSW_ADDRESS_OF(position_ipart_f),			// [0xA2E8]
		MSW_ADDRESS_OF(position_ipart_f),			// [0xA2E9]
		LSW_ADDRESS_OF(position_dpart_f),			// [0xA2EA]
		MSW_ADDRESS_OF(position_dpart_f),			// [0xA2EB]
		LSW_ADDRESS_OF(sh_t_ai_dec),				// [0xA2EC]
		LSW_ADDRESS_OF(kff_acc_dec),				// [0xA2ED]
		LSW_ADDRESS_OF(start_mode_command),			// [0xA2EE]
		LSW_ADDRESS_OF(adv_start_retries),			// [0xA2EF]
		LSW_ADDRESS_OF(max_enc_margin),				// [0xA2F0]
		MSW_ADDRESS_OF(max_enc_margin),				// [0xA2F1]
		LSW_ADDRESS_OF(real_min_err),				// [0xA2F2]
		MSW_ADDRESS_OF(real_min_err),				// [0xA2F3]
		LSW_ADDRESS_OF(real_t_si),					// [0xA2F4]
		MSW_ADDRESS_OF(real_t_si),					// [0xA2F5]
		LSW_ADDRESS_OF(real_spd),					// [0xA2F6]
		MSW_ADDRESS_OF(real_spd),					// [0xA2F7]
		LSW_ADDRESS_OF(velocity_bandwidth),			// [0xA2F8]
		LSW_ADDRESS_OF(time_on_reference),			// [0xA2F9]
		LSW_ADDRESS_OF(motor_current),				// [0xA2FA]
		LSW_ADDRESS_OF(error_code),					// [0xA2FB]
		LSW_ADDRESS_OF(real_min_pos_range),			// [0xA2FC]
		MSW_ADDRESS_OF(real_min_pos_range),			// [0xA2FD]
		LSW_ADDRESS_OF(real_max_pos_range),			// [0xA2FE]
		MSW_ADDRESS_OF(real_max_pos_range),			// [0xA2FF]
		LSW_ADDRESS_OF(real_sw_negative_limit),		// [0xA300]
		MSW_ADDRESS_OF(real_sw_negative_limit),		// [0xA301]
		LSW_ADDRESS_OF(real_sw_positive_limit),		// [0xA302]
		MSW_ADDRESS_OF(real_sw_positive_limit),		// [0xA303]
		LSW_ADDRESS_OF(real_c_acc),					// [0xA304]
		MSW_ADDRESS_OF(real_c_acc),					// [0xA305]
		LSW_ADDRESS_OF(real_pos_err),				// [0xA306]
		MSW_ADDRESS_OF(real_pos_err),				// [0xA307]
		LSW_ADDRESS_OF(real_speed_err_prot),		// [0xA308]
		MSW_ADDRESS_OF(real_speed_err_prot),		// [0xA309]
		LSW_ADDRESS_OF(real_pvt_pos0),				// [0xA30A]
		MSW_ADDRESS_OF(real_pvt_pos0),				// [0xA30B]
		LSW_ADDRESS_OF(saturation_current),			// [0xA30C]
		LSW_ADDRESS_OF(activate_csp_max_speed),		// [0xA30D]
		LSW_ADDRESS_OF(sap_value),					// [0xA30E]
		MSW_ADDRESS_OF(sap_value),					// [0xA30F]
		LSW_ADDRESS_OF(auxiliary_settings_register),// [0xA310]
		LSW_ADDRESS_OF(digin_status_low),			// [0xA311]
		LSW_ADDRESS_OF(digin_status_high),			// [0xA312]
		LSW_ADDRESS_OF(output_config_value),		// [0xA313]
		LSW_ADDRESS_OF(output_config_pins),			// [0xA314]
		LSW_ADDRESS_OF(number_of_steps),			// [0xA315]
		LSW_ADDRESS_OF(number_of_microsteps),		// [0xA316]
		LSW_ADDRESS_OF(brake_status),				// [0xA317]
		LSW_ADDRESS_OF(encoder_resolution),			// [0xA318]
		MSW_ADDRESS_OF(encoder_resolution),			// [0xA319]
		LSW_ADDRESS_OF(aux_capture_status),			// [0xA31A]
		LSW_ADDRESS_OF(auxiliary_settings_register2),	// [0xA31B]
		LSW_ADDRESS_OF(auxiliary_settings_register3),	// [0xA31C]
		LSW_ADDRESS_OF(ram_size),					// [0xA31D]
		LSW_ADDRESS_OF(p_internal_ram_value),		// [0xA31E]
		MSW_ADDRESS_OF(p_internal_ram_value),		// [0xA31F]
		LSW_ADDRESS_OF(ram_value),					// [0xA320]
		MSW_ADDRESS_OF(ram_value),					// [0xA321]
		LSW_ADDRESS_OF(ram_write_vaule),			// [0xA322]
		MSW_ADDRESS_OF(ram_write_vaule),			// [0xA323]
		LSW_ADDRESS_OF(ram_write_request),			// [0xA324]
		LSW_ADDRESS_OF(esm_float_support),			// [0xA325]
		LSW_ADDRESS_OF(tml_int13_configuration),	// [0xA326]
		LSW_ADDRESS_OF(current_ia_st),				// [0xA327]
		LSW_ADDRESS_OF(current_ib_st),				// [0xA328]
		LSW_ADDRESS_OF(current_ic_st),				// [0xA329]
		LSW_ADDRESS_OF(current_id_st),				// [0xA32A]
		LSW_ADDRESS_OF(stepper_current_ia),			// [0xA32B]
		LSW_ADDRESS_OF(stepper_current_ib),			// [0xA32C]
		LSW_ADDRESS_OF(phy_drv.type),				// [0xA32D]
		LSW_ADDRESS_OF(phy_drv.error_register),		// [0xA32E]
		LSW_ADDRESS_OF(v_log_raw),					// [0xA32F]
		LSW_ADDRESS_OF(v_mot_raw),					// [0xA330]
		LSW_ADDRESS_OF(t_drive_raw),				// [0xA331]
		LSW_ADDRESS_OF(t_mot_raw),					// [0xA332]
		LSW_ADDRESS_OF(adc_sto_level_raw),			// [0xA333]
		LSW_ADDRESS_OF(dsp_debug_active),			// [0xA334]
		LSW_ADDRESS_OF(debug_error_register),		// [0xA335]
		LSW_ADDRESS_OF(debug_operation),			// [0xA336]
		LSW_ADDRESS_OF(debug_data_size),			// [0xA327]
		LSW_ADDRESS_OF(debug_address),				// [0xA338]
		MSW_ADDRESS_OF(debug_address),				// [0xA339]
		LSW_ADDRESS_OF(debug_data),					// [0xA33A]
		MSW_ADDRESS_OF(debug_data),					// [0xA33B]
		LSW_ADDRESS_OF(debug_set_mask),				// [0xA33C]
		MSW_ADDRESS_OF(debug_set_mask),				// [0xA33D]
		LSW_ADDRESS_OF(debug_reset_mask),			// [0xA33E]
		MSW_ADDRESS_OF(debug_reset_mask),			// [0xA33F]
		LSW_ADDRESS_OF(u_q_ref_freeze),				// [0xA340]
		LSW_ADDRESS_OF(u_q_ref_freeze_lim),			// [0xA341]
		LSW_ADDRESS_OF(new_freeze_control),			// [0xA342]
		LSW_ADDRESS_OF(err_max_fc),					// [0xA343]
		LSW_ADDRESS_OF(u_d_ref_freeze),				// [0xA344]
		LSW_ADDRESS_OF(logger_delayed_start),		// [0xA345]
		LSW_ADDRESS_OF(t_si_brut),					// [0xA346]
		MSW_ADDRESS_OF(t_si_brut),					// [0xA347]
		LSW_ADDRESS_OF(t_ai_brut),					// [0xA348]
		MSW_ADDRESS_OF(t_ai_brut),					// [0xA349]
		LSW_ADDRESS_OF(t_ai_no_filter),				// [0xA34A]
		MSW_ADDRESS_OF(t_ai_no_filter),				// [0xA34B]
		LSW_ADDRESS_OF(a1_tspd),					// [0xA34C]
		MSW_ADDRESS_OF(a1_tspd),					// [0xA34D]
		LSW_ADDRESS_OF(b0_tspd),					// [0xA34E]
		MSW_ADDRESS_OF(b0_tspd),					// [0xA34F]
		LSW_ADDRESS_OF(a1_tacc),					// [0xA350]
		MSW_ADDRESS_OF(a1_tacc),					// [0xA351]
		LSW_ADDRESS_OF(b0_tacc),					// [0xA352]
		MSW_ADDRESS_OF(b0_tacc),					// [0xA353]
		LSW_ADDRESS_OF(tacc_filter_option),			// [0xA354]
		LSW_ADDRESS_OF(wait_tspd_0),				// [0xA355]
		LSW_ADDRESS_OF(tacc_threshold_pos),			// [0xA356]
		MSW_ADDRESS_OF(tacc_threshold_pos),			// [0xA357]
		LSW_ADDRESS_OF(tacc_threshold_neg),			// [0xA358]
		MSW_ADDRESS_OF(tacc_threshold_neg),			// [0xA359]
		LSW_ADDRESS_OF(logger_from_axis_off),		// [0xA35A]
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA35B]		XXX: free spot
		LSW_ADDRESS_OF(max_current_torque),			// [0xA35C]
		MSW_ADDRESS_OF(max_current_torque),			// [0xA35D]
		LSW_ADDRESS_OF(rate_current),				// [0xA35E]
		MSW_ADDRESS_OF(rate_current),				// [0xA35F]
		LSW_ADDRESS_OF(torque_slope),				// [0xA360]
		MSW_ADDRESS_OF(torque_slope),				// [0xA361]
		LSW_ADDRESS_OF(time_lim_halls),				// [0xA362]
		MSW_ADDRESS_OF(time_lim_halls),				// [0xA363]
		LSW_ADDRESS_OF(change_algh_threshold),		// [0xA364]
		MSW_ADDRESS_OF(change_algh_threshold),		// [0xA365]
		LSW_ADDRESS_OF(pos_hall),					// [0xA366]
		LSW_ADDRESS_OF(encoder_filtering_fdbk1),	// [0xA367]
		LSW_ADDRESS_OF(encoder_filtering_fdbk2),	// [0xA368]
		LSW_ADDRESS_OF(cst_with_speed_limit),		// [0xA369]
		LSW_ADDRESS_OF(max_motor_speed),			// [0xA36A]
		MSW_ADDRESS_OF(max_motor_speed),			// [0xA36B]
		LSW_ADDRESS_OF(ia_i2t_integral),			// [0xA36C]
		MSW_ADDRESS_OF(ia_i2t_integral),			// [0xA36D]
		LSW_ADDRESS_OF(ib_i2t_integral),			// [0xA36E]
		MSW_ADDRESS_OF(ib_i2t_integral),			// [0xA36F]
		LSW_ADDRESS_OF(ic_i2t_integral),			// [0xA370]
		MSW_ADDRESS_OF(ic_i2t_integral),			// [0xA371]
		LSW_ADDRESS_OF(ia_i2t_integral_drive),		// [0xA372]
		MSW_ADDRESS_OF(ia_i2t_integral_drive),		// [0xA373]
		LSW_ADDRESS_OF(ib_i2t_integral_drive),		// [0xA374]
		MSW_ADDRESS_OF(ib_i2t_integral_drive),		// [0xA375]
		LSW_ADDRESS_OF(ic_i2t_integral_drive),		// [0xA376]
		MSW_ADDRESS_OF(ic_i2t_integral_drive),		// [0xA377]
		LSW_ADDRESS_OF(i2t_trigger_cause),			// [0xA378]
		LSW_ADDRESS_OF(i_i2tprot_drive_phase),		// [0xA379]
		LSW_ADDRESS_OF(sf_i2t_drive_phase),			// [0xA37A]
		LSW_ADDRESS_OF(i_i2t_prot_phase),			// [0xA37B]
		LSW_ADDRESS_OF(sf_i2t_phase),				// [0xA37C]
		LSW_ADDRESS_OF(ia2_filtered),				// [0xA37D]
		LSW_ADDRESS_OF(ib2_filtered),				// [0xA37E]
		LSW_ADDRESS_OF(ic2_filtered),				// [0xA37F]
		LSW_ADDRESS_OF(var_bq_filtered),			// [0xA380]
		MSW_ADDRESS_OF(var_bq_filtered),			// [0xA381]
		LSW_ADDRESS_OF(bq_var_address),				// [0xA382]
		LSW_ADDRESS_OF(bq_var_type),				// [0xA383]
		LSW_ADDRESS_OF(var_bq_a1),					// [0xA384]
		MSW_ADDRESS_OF(var_bq_a1),					// [0xA385]
		LSW_ADDRESS_OF(var_bq_b0),					// [0xA386]
		MSW_ADDRESS_OF(var_bq_b0),					// [0xA387]
		LSW_ADDRESS_OF(can_motor_speed),			// [0xA388]
		MSW_ADDRESS_OF(can_motor_speed),			// [0xA389]
		LSW_ADDRESS_OF(can_load_speed),				// [0xA38A]
		MSW_ADDRESS_OF(can_load_speed),				// [0xA38B]
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA38C]			//XXX: RESERVED
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA38D]			//XXX: RESERVED
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA38E]			//XXX: RESERVED
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA38F]			//XXX: RESERVED
		LSW_ADDRESS_OF(biss_option_reading),		// [0xA390]
		LSW_ADDRESS_OF(remove_ack),					// [0xA391]
		LSW_ADDRESS_OF(start_byte),					// [0xA392]
		LSW_ADDRESS_OF(endat_treshold_clock_cycles),// [0xA393]
		LSW_ADDRESS_OF(endat_additional_clock),		// [0xA394]
		LSW_ADDRESS_OF(endat_additional_option),	// [0xA395]
		LSW_ADDRESS_OF(NMS_b_NodeState),			// [0xA396]
		LSW_ADDRESS_OF(kp_th),						// [0xA397]
		LSW_ADDRESS_OF(ki_th),						// [0xA398]
		LSW_ADDRESS_OF(sft_ki_th),					// [0xA399]
		LSW_ADDRESS_OF(sft_kp_th),					// [0xA39A]
		LSW_ADDRESS_OF(komega_th),					// [0xA39B]
		LSW_ADDRESS_OF(theta_offset),				// [0xA39C]
		LSW_ADDRESS_OF(sat_theta),					// [0xA39D]
		LSW_ADDRESS_OF(max_theta_sat),				// [0xA39E]
		LSW_ADDRESS_OF(theta_c),					// [0xA39F]
		LSW_ADDRESS_OF(theta_fdbk),					// [0xA3A0]
		LSW_ADDRESS_OF(en_theta_sat),				// [0xA3A1]
		LSW_ADDRESS_OF(err_pos),					// [0xA3A2]
		LSW_ADDRESS_OF(i_d_cmd),					// [0xA3A3]
		LSW_ADDRESS_OF(is_integral_enabled_q),		// [0xA3A4]
		LSW_ADDRESS_OF(is_integral_enabled_d),		// [0xA3A5]	
		LSW_ADDRESS_OF(theta_c_long),				// [0xA3A6]
		MSW_ADDRESS_OF(theta_c_long),				// [0xA3A7]
		LSW_ADDRESS_OF(theta_cp),					// [0xA3A8]
		MSW_ADDRESS_OF(theta_cp),					// [0xA3A9]
		LSW_ADDRESS_OF(theta_ci),					// [0xA3AA]
		MSW_ADDRESS_OF(theta_ci),					// [0xA3AB]
		LSW_ADDRESS_OF(actual_position_faster),		// [0xA3AC]
		MSW_ADDRESS_OF(actual_position_faster),		// [0xA3AD]
		LSW_ADDRESS_OF(t_pi_1),						// [0xA3AE]
		MSW_ADDRESS_OF(t_pi_1),						// [0xA3AF]
		LSW_ADDRESS_OF(target_position_faster),		// [0xA3B0]
		MSW_ADDRESS_OF(target_position_faster),		// [0xA3B1]
		LSW_ADDRESS_OF(u_b_ref_long),				// [0xA3B2]
		MSW_ADDRESS_OF(u_b_ref_long),				// [0xA3B3]
		LSW_ADDRESS_OF(u_a_ref_long),				// [0xA3B4]
		MSW_ADDRESS_OF(u_a_ref_long),				// [0xA3B5]
		LSW_ADDRESS_OF(u_q_ref_long),				// [0xA3B6]
		MSW_ADDRESS_OF(u_q_ref_long),				// [0xA3B7]
		LSW_ADDRESS_OF(u_d_ref_long),				// [0xA3B8]
		MSW_ADDRESS_OF(u_d_ref_long),				// [0xA3B9]
		LSW_ADDRESS_OF(l_KPI),						// [0xA3BA]
		MSW_ADDRESS_OF(l_KPI),						// [0xA3BB]
		LSW_ADDRESS_OF(l_KII),						// [0xA3BC]
		MSW_ADDRESS_OF(l_KII),						// [0xA3BD]
		LSW_ADDRESS_OF(qicrtq_p),					// [0xA3BE]
		MSW_ADDRESS_OF(qicrtq_p),					// [0xA3BF]
		LSW_ADDRESS_OF(qicrtq_i),					// [0xA3C0]
		MSW_ADDRESS_OF(qicrtq_i),					// [0xA3C1]
		LSW_ADDRESS_OF(qicrtd_p),					// [0xA3C2]
		MSW_ADDRESS_OF(qicrtd_p),					// [0xA3C3]
		LSW_ADDRESS_OF(qicrtd_i),					// [0xA3C4]	
		MSW_ADDRESS_OF(qicrtd_i),					// [0xA3C5]
		LSW_ADDRESS_OF(spd_fast),					// [0xA3C6]
		LSW_ADDRESS_OF(motor_current_copen),		// [0xA3C7]
		LSW_ADDRESS_OF(asr4),						// [0xA3C8]
		MSW_ADDRESS_OF(asr4),						// [0xA3C9]
		LSW_ADDRESS_OF(motor_delta_theta_position),	// [0xA3CA]
		MSW_ADDRESS_OF(motor_delta_theta_position),	// [0xA3CB]
		LSW_ADDRESS_OF(mer_1_copen),				// [0xA3CC]
		LSW_ADDRESS_OF(srl_mask),					// [0xA3CD]
		LSW_ADDRESS_OF(sync_margin_no_time_stamp),	// [0xA3CE]
		LSW_ADDRESS_OF(sync_rate_no_time_stamp),	// [0xA3CF]
		LSW_ADDRESS_OF(internal_t_drive),			// [0xA3D0]
		LSW_ADDRESS_OF(read_internal_temp),			// [0xA3D1]
		LSW_ADDRESS_OF(der2_mask),					// [0xA3D2]
		LSW_ADDRESS_OF(current_scale_amplification),// [0xA3D3]
		LSW_ADDRESS_OF(tonerr_sol_pid),				// [0xA3D4]
		LSW_ADDRESS_OF(errprot_sol_pid),			// [0xA3D5]
		MSW_ADDRESS_OF(errprot_sol_pid),			// [0xA3D6]
		LSW_ADDRESS_OF(sol_dtheta_inc),				// [0xA3D7]
		MSW_ADDRESS_OF(sol_dtheta_inc),				// [0xA3D8]
		LSW_ADDRESS_OF(active_control_mode),		// [0xA3D9]
		LSW_ADDRESS_OF(sol_pid_active),				// [0xA3DA]
		LSW_ADDRESS_OF(null_padding_variable),		// [0xA3DB]	XXX: free spot
		LSW_ADDRESS_OF(exotic_position_offset_long),// [0xA3DC]
		MSW_ADDRESS_OF(exotic_position_offset_long),// [0xA3DD]
		LSW_ADDRESS_OF(fault_reaction_option_code_pdpint),			// [0xA3DE]
		LSW_ADDRESS_OF(fault_reaction_option_code_ctrl_err),		// [0xA3DF]
		LSW_ADDRESS_OF(fault_reaction_option_code_comm),			// [0xA3E0]
		LSW_ADDRESS_OF(fault_reaction_option_code_overcrt),			// [0xA3E1]
		LSW_ADDRESS_OF(fault_reaction_option_code_i2t),				// [0xA3E2]
		LSW_ADDRESS_OF(fault_reaction_option_code_i2t_drv),			// [0xA3E3]
		LSW_ADDRESS_OF(fault_reaction_option_motor_temp),			// [0xA3E4]
		LSW_ADDRESS_OF(fault_reaction_option_drive_temp),			// [0xA3E5]
		LSW_ADDRESS_OF(fault_reaction_option_overvoltage),			// [0xA3E6]
		LSW_ADDRESS_OF(fault_reaction_option_undervoltage),			// [0xA3E7]
		LSW_ADDRESS_OF(fault_reaction_option_code_ena),				// [0xA3E8]
		LSW_ADDRESS_OF(adc_current_ia_highscale_offset),			// [0xA3E9]
		LSW_ADDRESS_OF(adc_current_ib_highscale_offset),			// [0xA3EA]
		LSW_ADDRESS_OF(adc_current_ic_highscale_offset),			// [0xA3EB]
		LSW_ADDRESS_OF(adc_current_id_highscale_offset),			// [0xA3EC]
		LSW_ADDRESS_OF(adc_current_ia_lowscale_offset),				// [0xA3ED]
		LSW_ADDRESS_OF(adc_current_ib_lowscale_offset),				// [0xA3EE]
		LSW_ADDRESS_OF(adc_current_ic_lowscale_offset),				// [0xA3EF]
		LSW_ADDRESS_OF(adc_current_id_lowscale_offset),				// [0xA3F0]
		LSW_ADDRESS_OF(external_chopping_res_cfg),					// [0xA3F1]
		LSW_ADDRESS_OF(absolute_position_fdbk1),					// [0xA3F2]
		MSW_ADDRESS_OF(absolute_position_fdbk1),					// [0xA3F3]
		LSW_ADDRESS_OF(max_spd_dualuse),							// [0xA3F4]
		LSW_ADDRESS_OF(hall_max_spd_dualuse),						// [0xA3F5]
		LSW_ADDRESS_OF(fault_override_option_code),					// [0xA3F6]
		LSW_ADDRESS_OF(null_padding_variable),						// [0xA3F7] XXX: free spot
		LSW_ADDRESS_OF(absolute_feedback1_data_buffer_LSB),			// [0xA3F8]
		MSW_ADDRESS_OF(absolute_feedback1_data_buffer_LSB),			// [0xA3F9]
		LSW_ADDRESS_OF(absolute_feedback1_data_buffer_MSB),			// [0xA3FA]
		MSW_ADDRESS_OF(absolute_feedback1_data_buffer_MSB),			// [0xA3FB]
		LSW_ADDRESS_OF(absolute_feedback2_data_buffer_LSB),			// [0xA3FC]
		MSW_ADDRESS_OF(absolute_feedback2_data_buffer_LSB),			// [0xA3FD]
		LSW_ADDRESS_OF(absolute_feedback2_data_buffer_MSB),			// [0xA3FE]
		MSW_ADDRESS_OF(absolute_feedback2_data_buffer_MSB),			// [0xA3FF]
		LSW_ADDRESS_OF(feedback1_leading_zeroes),					// [0xA400]
		LSW_ADDRESS_OF(feedback2_leading_zeroes),					// [0xA401]
		LSW_ADDRESS_OF(feedback1_trailing_bits_shift),				// [0xA402]
		LSW_ADDRESS_OF(feedback2_trailing_bits_shift),				// [0xA403]
		LSW_ADDRESS_OF(feedback1_computed_crc),						// [0xA404]
		LSW_ADDRESS_OF(feedback1_receive_crc),						// [0xA405]
		LSW_ADDRESS_OF(feedback2_computed_crc),						// [0xA406]
		LSW_ADDRESS_OF(feedback2_receive_crc),						// [0xA407]
		LSW_ADDRESS_OF(crt_gain_selected),							// [0xA408]
		LSW_ADDRESS_OF(biss_option_reading_fdbk1),					// [0xA409]
		LSW_ADDRESS_OF(remove_ack_fdbk1),							// [0xA40A]
		LSW_ADDRESS_OF(start_byte_fdbk1),							// [0xA40B]
		LSW_ADDRESS_OF(analog_id0),									// [0xA40C]
		LSW_ADDRESS_OF(analog_id1),									// [0xA40D]
		LSW_ADDRESS_OF(analog_id2),									// [0xA40E]
		LSW_ADDRESS_OF(brake_as_MCIV),								// [0xA40F]
};


/*******************************************************************/
/*************************** DEBUG VARIABLES ***********************/
int16_t debug_1;
int16_t debug_2;
int16_t debug_3;
int16_t debug_4;
int16_t debug_5;
int16_t debug_6;
int16_t debug_7;
int16_t debug_8;
int16_t debug_9;

/*************************************************************************
* Static variables
*************************************************************************/



/*************************************************************************
* Local function prototypes
*************************************************************************/



/*************************************************************************
* Public functions bodies
*************************************************************************/



/*************************************************************************
* Private functions bodies
*************************************************************************/



/* End of file */
