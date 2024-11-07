/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnegative.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 3,  /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2795"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 29,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2795"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 32,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2795"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 48,/* lineNo */
  "rgb2hsv",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\images\\rgb2hsv.m"/* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 46,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m"/* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 45,/* lineNo */
  "graythresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 48,/* lineNo */
  "graythresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 131,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 203,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 166,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 85,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtBCInfo c1_emlrtBCI = { 0,  /* iFirst */
  57599,                               /* iLast */
  26,                                  /* lineNo */
  16,                                  /* colNo */
  "masked_rgb",                        /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2795",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_emlrtDCI = { 26, /* lineNo */
  16,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2795",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1051,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1052,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1053,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1054,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static real_T c1_graythresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, uint8_T c1_I[19200]);
static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200]);
static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200]);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c1_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    68U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_flightControlSystem", 0, -1, 1161);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  c1_sNrqT4fAWIMnTNkfSKQUNxE c1_options;
  emlrtStack c1_b_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c1_T;
  real_T c1_T_;
  real_T c1_b_T;
  real_T c1_b_varargin_1;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_level;
  real_T c1_varargin_1;
  int32_T c1_b_i;
  int32_T c1_b_jcol;
  int32_T c1_b_jtilecol;
  int32_T c1_b_k;
  int32_T c1_end;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_iacol;
  int32_T c1_ibmat;
  int32_T c1_ibtile;
  int32_T c1_jcol;
  int32_T c1_jtilecol;
  int32_T c1_k;
  uint8_T c1_gray_image[19200];
  boolean_T c1_b[57600];
  boolean_T c1_bv[19200];
  boolean_T c1_bv1[19200];
  boolean_T c1_mask1[19200];
  boolean_T c1_mask2[19200];
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 57600; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_rgb_image)[c1_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_b_st.site = &c1_emlrtRSI;
  rgb2hsv_tbb_uint8(&(*chartInstance->c1_rgb_image)[0], 19200.0,
                    &chartInstance->c1_hsv_image[0], true);
  c1_i1 = 0;
  for (c1_i2 = 0; c1_i2 < 160; c1_i2++) {
    for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
      c1_mask1[c1_i4 + c1_i1] = (chartInstance->c1_hsv_image[c1_i4 + c1_i1] >=
        0.0);
    }

    c1_i1 += 120;
  }

  c1_i3 = 0;
  for (c1_i5 = 0; c1_i5 < 160; c1_i5++) {
    for (c1_i7 = 0; c1_i7 < 120; c1_i7++) {
      c1_bv[c1_i7 + c1_i3] = (chartInstance->c1_hsv_image[c1_i7 + c1_i3] <= 0.1);
    }

    c1_i3 += 120;
  }

  for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
    c1_mask1[c1_i6] = (c1_mask1[c1_i6] && c1_bv[c1_i6]);
  }

  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 160; c1_i9++) {
    for (c1_i11 = 0; c1_i11 < 120; c1_i11++) {
      c1_bv[c1_i11 + c1_i8] = (chartInstance->c1_hsv_image[(c1_i11 + c1_i8) +
        19200] >= 0.3);
    }

    c1_i8 += 120;
  }

  c1_i10 = 0;
  for (c1_i12 = 0; c1_i12 < 160; c1_i12++) {
    for (c1_i14 = 0; c1_i14 < 120; c1_i14++) {
      c1_bv1[c1_i14 + c1_i10] = (chartInstance->c1_hsv_image[(c1_i14 + c1_i10) +
        19200] <= 1.0);
    }

    c1_i10 += 120;
  }

  for (c1_i13 = 0; c1_i13 < 19200; c1_i13++) {
    c1_bv[c1_i13] = (c1_bv[c1_i13] && c1_bv1[c1_i13]);
  }

  for (c1_i15 = 0; c1_i15 < 19200; c1_i15++) {
    c1_mask1[c1_i15] = (c1_mask1[c1_i15] && c1_bv[c1_i15]);
  }

  c1_i16 = 0;
  for (c1_i17 = 0; c1_i17 < 160; c1_i17++) {
    for (c1_i19 = 0; c1_i19 < 120; c1_i19++) {
      c1_bv[c1_i19 + c1_i16] = (chartInstance->c1_hsv_image[(c1_i19 + c1_i16) +
        38400] >= 0.1);
    }

    c1_i16 += 120;
  }

  c1_i18 = 0;
  for (c1_i20 = 0; c1_i20 < 160; c1_i20++) {
    for (c1_i22 = 0; c1_i22 < 120; c1_i22++) {
      c1_bv1[c1_i22 + c1_i18] = (chartInstance->c1_hsv_image[(c1_i22 + c1_i18) +
        38400] <= 1.0);
    }

    c1_i18 += 120;
  }

  for (c1_i21 = 0; c1_i21 < 19200; c1_i21++) {
    c1_bv[c1_i21] = (c1_bv[c1_i21] && c1_bv1[c1_i21]);
  }

  for (c1_i23 = 0; c1_i23 < 19200; c1_i23++) {
    c1_mask1[c1_i23] = (c1_mask1[c1_i23] && c1_bv[c1_i23]);
  }

  c1_i24 = 0;
  for (c1_i25 = 0; c1_i25 < 160; c1_i25++) {
    for (c1_i27 = 0; c1_i27 < 120; c1_i27++) {
      c1_mask2[c1_i27 + c1_i24] = (chartInstance->c1_hsv_image[c1_i27 + c1_i24] >=
        0.9);
    }

    c1_i24 += 120;
  }

  c1_i26 = 0;
  for (c1_i28 = 0; c1_i28 < 160; c1_i28++) {
    for (c1_i30 = 0; c1_i30 < 120; c1_i30++) {
      c1_bv[c1_i30 + c1_i26] = (chartInstance->c1_hsv_image[c1_i30 + c1_i26] <=
        1.0);
    }

    c1_i26 += 120;
  }

  for (c1_i29 = 0; c1_i29 < 19200; c1_i29++) {
    c1_mask2[c1_i29] = (c1_mask2[c1_i29] && c1_bv[c1_i29]);
  }

  c1_i31 = 0;
  for (c1_i32 = 0; c1_i32 < 160; c1_i32++) {
    for (c1_i34 = 0; c1_i34 < 120; c1_i34++) {
      c1_bv[c1_i34 + c1_i31] = (chartInstance->c1_hsv_image[(c1_i34 + c1_i31) +
        19200] >= 0.3);
    }

    c1_i31 += 120;
  }

  c1_i33 = 0;
  for (c1_i35 = 0; c1_i35 < 160; c1_i35++) {
    for (c1_i37 = 0; c1_i37 < 120; c1_i37++) {
      c1_bv1[c1_i37 + c1_i33] = (chartInstance->c1_hsv_image[(c1_i37 + c1_i33) +
        19200] <= 1.0);
    }

    c1_i33 += 120;
  }

  for (c1_i36 = 0; c1_i36 < 19200; c1_i36++) {
    c1_bv[c1_i36] = (c1_bv[c1_i36] && c1_bv1[c1_i36]);
  }

  for (c1_i38 = 0; c1_i38 < 19200; c1_i38++) {
    c1_mask2[c1_i38] = (c1_mask2[c1_i38] && c1_bv[c1_i38]);
  }

  c1_i39 = 0;
  for (c1_i40 = 0; c1_i40 < 160; c1_i40++) {
    for (c1_i42 = 0; c1_i42 < 120; c1_i42++) {
      c1_bv[c1_i42 + c1_i39] = (chartInstance->c1_hsv_image[(c1_i42 + c1_i39) +
        38400] >= 0.1);
    }

    c1_i39 += 120;
  }

  c1_i41 = 0;
  for (c1_i43 = 0; c1_i43 < 160; c1_i43++) {
    for (c1_i45 = 0; c1_i45 < 120; c1_i45++) {
      c1_bv1[c1_i45 + c1_i41] = (chartInstance->c1_hsv_image[(c1_i45 + c1_i41) +
        38400] <= 1.0);
    }

    c1_i41 += 120;
  }

  for (c1_i44 = 0; c1_i44 < 19200; c1_i44++) {
    c1_bv[c1_i44] = (c1_bv[c1_i44] && c1_bv1[c1_i44]);
  }

  for (c1_i46 = 0; c1_i46 < 19200; c1_i46++) {
    c1_mask2[c1_i46] = (c1_mask2[c1_i46] && c1_bv[c1_i46]);
  }

  for (c1_i47 = 0; c1_i47 < 19200; c1_i47++) {
    c1_mask1[c1_i47] = (c1_mask1[c1_i47] || c1_mask2[c1_i47]);
  }

  for (c1_i48 = 0; c1_i48 < 57600; c1_i48++) {
    chartInstance->c1_masked_rgb[c1_i48] = (*chartInstance->c1_rgb_image)[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 19200; c1_i49++) {
    c1_mask1[c1_i49] = !c1_mask1[c1_i49];
  }

  for (c1_jtilecol = 0; c1_jtilecol < 3; c1_jtilecol++) {
    c1_b_jtilecol = c1_jtilecol;
    c1_ibtile = c1_b_jtilecol * 19200;
    for (c1_jcol = 0; c1_jcol < 160; c1_jcol++) {
      c1_b_jcol = c1_jcol;
      c1_iacol = c1_b_jcol * 120 - 1;
      c1_ibmat = (c1_ibtile + c1_b_jcol * 120) - 1;
      for (c1_k = 0; c1_k < 120; c1_k++) {
        c1_b_k = c1_k + 1;
        c1_b[c1_ibmat + c1_b_k] = c1_mask1[c1_iacol + c1_b_k];
      }
    }
  }

  c1_end = 57600;
  for (c1_b_i = 0; c1_b_i < c1_end; c1_b_i++) {
    if (c1_b[c1_b_i]) {
      c1_d = (real_T)c1_b_i;
      if (c1_d != (real_T)(int32_T)muDoubleScalarFloor(c1_d)) {
        emlrtIntegerCheckR2012b(c1_d, &c1_emlrtDCI, &c1_st);
      }

      c1_i50 = (int32_T)muDoubleScalarFloor(c1_d);
      if ((c1_i50 < 0) || (c1_i50 > 57599)) {
        emlrtDynamicBoundsCheckR2012b(c1_i50, 0, 57599, &c1_emlrtBCI, &c1_st);
      }

      chartInstance->c1_masked_rgb[c1_i50] = 0U;
    }
  }

  c1_b_st.site = &c1_b_emlrtRSI;
  rgb2gray_tbb_uint8(&chartInstance->c1_masked_rgb[0], 19200.0, &c1_gray_image[0],
                     true);
  c1_b_st.site = &c1_c_emlrtRSI;
  c1_level = c1_graythresh(chartInstance, &c1_b_st, c1_gray_image);
  c1_varargin_1 = c1_level;
  c1_b_varargin_1 = c1_varargin_1;
  c1_T_ = c1_b_varargin_1;
  c1_T = c1_T_;
  c1_options.t = c1_T;
  c1_b_T = c1_options.t;
  c1_d1 = 255.0 * c1_b_T;
  for (c1_i51 = 0; c1_i51 < 19200; c1_i51++) {
    (*chartInstance->c1_u)[c1_i51] = ((real_T)c1_gray_image[c1_i51] > c1_d1);
  }

  for (c1_i52 = 0; c1_i52 < 19200; c1_i52++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      (*chartInstance->c1_u)[c1_i52]);
  }
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(1, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_u, 11, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  int32_T c1_i;
  boolean_T c1_bv[19200];
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 0)), "u",
                      c1_bv);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    (*chartInstance->c1_u)[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
  sf_mex_destroy(&c1_st);
}

static real_T c1_graythresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, uint8_T c1_I[19200])
{
  static char_T c1_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c1_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c1_cv2[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_counts[256];
  real_T c1_localBins1[256];
  real_T c1_localBins2[256];
  real_T c1_localBins3[256];
  real_T c1_b_idx;
  real_T c1_b_k;
  real_T c1_b_p;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_i;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_k_a;
  real_T c1_k_c;
  real_T c1_l_a;
  real_T c1_level;
  real_T c1_m_a;
  real_T c1_maxval;
  real_T c1_mu_t;
  real_T c1_n_a;
  real_T c1_num_elems;
  real_T c1_num_maxval;
  real_T c1_o_a;
  real_T c1_out;
  real_T c1_sigma_b_squared;
  real_T c1_x;
  int32_T c1_a;
  int32_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_c_k;
  int32_T c1_d_a;
  int32_T c1_d_c;
  int32_T c1_e_a;
  int32_T c1_e_c;
  int32_T c1_e_k;
  int32_T c1_f_a;
  int32_T c1_f_c;
  int32_T c1_f_k;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_idx;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idx3;
  int32_T c1_idx4;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k;
  uint8_T c1_b_I[19200];
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_b;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_exitg1;
  boolean_T c1_isfinite_maxval;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_I[c1_i] = c1_I[c1_i];
  }

  c1_st.site = &c1_f_emlrtRSI;
  c1_b_st.site = &c1_h_emlrtRSI;
  c1_c_st.site = &c1_j_emlrtRSI;
  c1_out = 1.0;
  getnumcores(&c1_out);
  c1_c_st.site = &c1_i_emlrtRSI;
  memset(&c1_counts[0], 0, sizeof(real_T) << 8);
  memset(&c1_localBins1[0], 0, sizeof(real_T) << 8);
  memset(&c1_localBins2[0], 0, sizeof(real_T) << 8);
  memset(&c1_localBins3[0], 0, sizeof(real_T) << 8);
  for (c1_b_i = 4; c1_b_i <= 19200; c1_b_i += 4) {
    c1_i1 = c1_b_i - 3;
    if ((c1_i1 < 1) || (c1_i1 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i1, 1, 19200, &c1_b_emlrtBCI, &c1_c_st);
    }

    c1_idx1 = c1_b_I[c1_i1 - 1];
    c1_i2 = c1_b_i - 2;
    if ((c1_i2 < 1) || (c1_i2 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i2, 1, 19200, &c1_c_emlrtBCI, &c1_c_st);
    }

    c1_idx2 = c1_b_I[c1_i2 - 1];
    c1_i3 = c1_b_i - 1;
    if ((c1_i3 < 1) || (c1_i3 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i3, 1, 19200, &c1_d_emlrtBCI, &c1_c_st);
    }

    c1_idx3 = c1_b_I[c1_i3 - 1];
    if ((c1_b_i < 1) || (c1_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_i, 1, 19200, &c1_e_emlrtBCI, &c1_c_st);
    }

    c1_idx4 = c1_b_I[c1_b_i - 1];
    c1_c_a = c1_idx1 + 1;
    c1_c_c = c1_c_a - 1;
    c1_d_a = c1_idx1 + 1;
    c1_d_c = c1_d_a - 1;
    c1_localBins1[c1_c_c] = c1_localBins1[c1_d_c] + 1.0;
    c1_e_a = c1_idx2 + 1;
    c1_e_c = c1_e_a - 1;
    c1_f_a = c1_idx2 + 1;
    c1_f_c = c1_f_a - 1;
    c1_localBins2[c1_e_c] = c1_localBins2[c1_f_c] + 1.0;
    c1_g_a = c1_idx3 + 1;
    c1_g_c = c1_g_a - 1;
    c1_h_a = c1_idx3 + 1;
    c1_h_c = c1_h_a - 1;
    c1_localBins3[c1_g_c] = c1_localBins3[c1_h_c] + 1.0;
    c1_i_a = c1_idx4 + 1;
    c1_i_c = c1_i_a - 1;
    c1_j_a = c1_idx4 + 1;
    c1_j_c = c1_j_a - 1;
    c1_counts[c1_i_c] = c1_counts[c1_j_c] + 1.0;
  }

  while (c1_b_i - 3 <= 19200) {
    c1_idx = c1_b_I[c1_b_i - 4];
    c1_a = c1_idx + 1;
    c1_c = c1_a - 1;
    c1_b_a = c1_idx + 1;
    c1_b_c = c1_b_a - 1;
    c1_counts[c1_c] = c1_counts[c1_b_c] + 1.0;
    c1_b_i++;
  }

  for (c1_c_i = 0; c1_c_i < 256; c1_c_i++) {
    c1_d_i = (real_T)c1_c_i + 1.0;
    c1_counts[(int32_T)c1_d_i - 1] = ((c1_counts[(int32_T)c1_d_i - 1] +
      c1_localBins1[(int32_T)c1_d_i - 1]) + c1_localBins2[(int32_T)c1_d_i - 1])
      + c1_localBins3[(int32_T)c1_d_i - 1];
  }

  c1_st.site = &c1_g_emlrtRSI;
  c1_b_st.site = &c1_l_emlrtRSI;
  c1_c_st.site = &c1_n_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 256)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x = c1_counts[(int32_T)c1_b_k - 1];
    c1_b_x = c1_x;
    c1_b_b = muDoubleScalarIsInf(c1_b_x);
    c1_b1 = !c1_b_b;
    c1_c_b = c1_b1;
    if (c1_c_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c1_c_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_c_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_c_st.site = &c1_n_emlrtRSI;
  c1_num_elems = 0.0;
  for (c1_c_k = 0; c1_c_k < 256; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_num_elems += c1_counts[(int32_T)c1_d_k - 1];
  }

  c1_localBins1[0] = c1_counts[0] / c1_num_elems;
  c1_localBins2[0] = c1_localBins1[0];
  for (c1_e_k = 0; c1_e_k < 255; c1_e_k++) {
    c1_d_k = (real_T)c1_e_k + 2.0;
    c1_b_p = c1_counts[(int32_T)c1_d_k - 1] / c1_num_elems;
    c1_localBins1[(int32_T)c1_d_k - 1] = c1_localBins1[(int32_T)(c1_d_k - 1.0) -
      1] + c1_b_p;
    c1_localBins2[(int32_T)c1_d_k - 1] = c1_localBins2[(int32_T)(c1_d_k - 1.0) -
      1] + c1_b_p * c1_d_k;
  }

  c1_mu_t = c1_localBins2[255];
  c1_maxval = rtMinusInf;
  c1_b_idx = 0.0;
  c1_num_maxval = 0.0;
  for (c1_f_k = 0; c1_f_k < 255; c1_f_k++) {
    c1_d_k = (real_T)c1_f_k + 1.0;
    c1_b_st.site = &c1_m_emlrtRSI;
    c1_k_a = c1_mu_t * c1_localBins1[(int32_T)c1_d_k - 1] - c1_localBins2
      [(int32_T)c1_d_k - 1];
    c1_c_st.site = &c1_o_emlrtRSI;
    c1_l_a = c1_k_a;
    c1_m_a = c1_l_a;
    c1_n_a = c1_m_a;
    c1_o_a = c1_n_a;
    c1_k_c = c1_o_a * c1_o_a;
    c1_sigma_b_squared = c1_k_c / (c1_localBins1[(int32_T)c1_d_k - 1] * (1.0 -
      c1_localBins1[(int32_T)c1_d_k - 1]));
    if (c1_sigma_b_squared > c1_maxval) {
      c1_maxval = c1_sigma_b_squared;
      c1_b_idx = c1_d_k;
      c1_num_maxval = 1.0;
    } else if (c1_sigma_b_squared == c1_maxval) {
      c1_b_idx += c1_d_k;
      c1_num_maxval++;
    }
  }

  c1_c_x = c1_maxval;
  c1_d_x = c1_c_x;
  c1_d_b = muDoubleScalarIsInf(c1_d_x);
  c1_b2 = !c1_d_b;
  c1_isfinite_maxval = c1_b2;
  if (c1_isfinite_maxval) {
    c1_b_idx /= c1_num_maxval;
    c1_level = (c1_b_idx - 1.0) / 255.0;
  } else {
    c1_level = 0.0;
  }

  return c1_level;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200])
{
  int32_T c1_i;
  boolean_T c1_bv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_rgb_image = (uint8_T (*)[57600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_u = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1189972814U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3213493993U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3729726847U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2384536335U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,3);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOk3QNLPQkC/AJBVCg0XEAAALBwMsA=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sa6AXd4gDtE9hDO1sEOhiJG";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWN1u40QUnnRLxSJYirRiuVh+LrlbVosQaBG0TZwSaEmE0wVxs5rYx/ao4xnv/KQND8Eb8BS",
    "LBI+AxAvwGFxyyRnHSUMaUo8jbQuWnGRsf3POfPOdH4e0escEjzt47t0jZAe/X8Zzi0yPl6pxa+",
    "GcXt8mn1bjwSuERBlVpicSSfyPSMaQgghtkrBzT6yw+YAqmusGdgXN4RvQklvDpPBznokEFIgIJ",
    "yikMl52NcstZ+K0a0XkLOtvMxZlYSYtjw9wQhr3BZ/8m93CmgFa7DAFkekCxCZT0qZZl9N0PQvK",
    "nLUziE61zb250mBCW7il6mPLDSs4BOcQ9YQ2FFnQV6w3NNRA25x7K4TpcIaWecEZFfW5zqgOoUB",
    "1GDgpYvzsW4Ps1bSL9kZMUCMVozzIedspvCZ2wNHPY5Q19+bZ5KYDI5umTKSOXWVzELh+1EkNrp",
    "K2HIOiKfSFZwy61QXn5QbPdVk/BntOlo1i0ObTXdGNsKXdYIwM6YZ2u5FoU861H3YoiyMYAy/td",
    "6ihDbBT+x5grVk8lE+oclHgGUlWsGcWKmxbipjV3+HxEqpMuF9j8qwBZ7mTFMRI89z1+URXadJq",
    "I/M2hlHn6KimvcvYnjCgEhpB7dynKNOADpe68rQbM01H3KGRJVOusvYMIBpDiU6s6JxJdYoc+yb",
    "ZC65cJPihIU6hAwbKhBGgup9Qbmv6nGvMcE4eJxozlp9dxLr4aQSOaJRB7OoJ43AM2k2ga+dnrC",
    "P7uNoxM5MO6Eixom4kWQ0xFhLH0nBSwIk4FfJMdJXMw6ojWKMrAMwaVAksCwdYltSki87X81rBs",
    "6FTVpP2LKeG05HTxiEIrCxura4S0gijKhDYuqFDm2BD9gOWdqGZNthOTYIyBuKyH32r5dePvlGN",
    "H81jqaeHCneKYhkW2Cntj8pmD4Ysh/JCSLGnmA6rw9n9gFzYvb213u4W/mo1xJENcV8s4LZX8PP",
    "mAm63GkcPnyacpZlLwkZJHk6Q9/yyH6/W4HuV/8s4cgl3wfPs+/0FfGuFXbLwvcn+7C3gXluys7",
    "2E26k4+/2nB/cf//jOL6//+vPo+YO3n29i/zdPPd+pxvdn/dm8go0vJfk6eri3pAc31vSj/e/iD",
    "9OOCT7JOv2HOuhn7MvDRvE3u/4engYTXJkvVdSLq3ctN6Z2+g7g5v94wd+dK+a/vaAnQv78fDP8",
    "3b3lfdy+Ar+Lv+ySbm96nriuvHSdftbJW60XjCMvGLfp+nzz8X/9+XV5gCw9v3uD10HW5Cefunz",
    "T1vUH8atD71bjz+bvzO2M8XhF117dxsY6WXX3f6Lvvzz5m/UJgeOv+tPv+0f7gvIJtunT16Dq8k",
    "C5/5vmtxRQvfpd6DrqUJ34dk/f+kd83yKHB181rmN/A5ld+68=",
    ""
  };

  static char newstr [1401] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(472882635U));
  ssSetChecksum1(S,(3072233019U));
  ssSetChecksum2(S,(1656010767U));
  ssSetChecksum3(S,(3005034419U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
