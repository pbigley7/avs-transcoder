/*$T defines.h GC 1.140 10/28/07 15:38:24 */


/*$6
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */


#ifndef _DEFINES_H_
#define _DEFINES_H_
//#define ROI_ENABLE
#define AVS
#define TRACE  0  /* !< 0:Trace off 1:Trace on */
#define snprintf  _snprintf
#define _THREE_STEP_MOTION_SEARCH_
//#define _OUTPUT_DEC_IMG_
//#define _ME_FOR_RATE_CONTROL_
/*
 * define FastME ;
 * #define FIELDINTE
 */
#define AVS_OUT_BUFFER_SIZE  (1024 * 1024 * 4)
#define MAX_ITEMS_TO_PARSE  10000
#define MAXHEADERSIZE 100

#define CACHELINESIZE 32

#define NUM_2D_TABLES 4
#define CODE2D_ESCAPE_SYMBOL 59
#define Q_BITS          21
#define EP (edgepixels+20)

#define IS_FW ((best8x8pdir[mode][k]==0 || best8x8pdir[mode][k]==2) && (mode!=P8x8 || best8x8mode[k]!=0 || !bframe))
#define IS_BW ((best8x8pdir[mode][k]==1 || best8x8pdir[mode][k]==2) && (mode!=P8x8 || best8x8mode[k]!=0))

#define RM  "5"
#define VERSION "5.2c"

#define AVS_TYPE_NOTHING  0 /* decoder only (encoder stats): nothing was decoded/encoded */
#define AVS_TYPE_AUTO     0 /* encoder: automatically determine coding type */
#define AVS_TYPE_I     1 /* intra frame */
#define AVS_TYPE_P     2 /* predicted frame */
#define AVS_TYPE_B     3 /* bidirectionally encoded */

#define MAXSLICEPERPICTURE    100
#define ET_SIZE        300  /* !< size of error text buffer */
#define NUM_PIC_TYPE      5

#define PROFILE_IDC      66
#define LEVEL_IDC      21

#define TOTRUN_NUM      15
#define LUMA_8x8      2
#define LUMA_8x4      3
#define LUMA_4x8      4
#define LUMA_4x4      5

#define max(a, b)      (((a) > (b)) ? (a) : (b))
#define min(a, b)      (((a) < (b)) ? (a) : (b))
#define clamp(a, b, c)    ((a) < (b) ? (b) : ((a) > (c) ? (c) : (a)))  /* !< clamp a to the range of [b; c] */

#define LOG2_MAX_FRAME_NUM_MINUS4  4      /* POC200301 moved from defines.h */

/*
 * FLAGS and DEFINES for new chroma intra prediction, Dzung Hoang ;
 * Threshold values to zero out quantized transform coefficients. ;
 * Recommend that _CHROMA_COEFF_COST_ be low to improve chroma quality
 */
#define _LUMA_COEFF_COST_  4        /* !< threshold for luma coeffs */
#define _CHROMA_COEFF_COST_  4        /* !< threshold for chroma coeffs, used to be 7 */

#define IMG_PAD_SIZE    16
#define absm(A)      ((A) < (0) ? (-(A)) : (A))  /* !< abs macro, faster than procedure */
#define MAX_VALUE1    9999    /* !< used for start value for some variables */

#define Clip1(a)    ((a) > 255 ? 255 : ((a) < 0 ? 0 : (a)))
#define Clip3(min, max, val)  (((val) < (min)) ? (min) : (((val) > (max)) ? (max) : (val)))

/* FLAGS and DEFINES for AVS. */
#define B8_SIZE        8  /* block size of block transformed by AVS */
#define DIRECT        0
#define INTER16x16      1
#define INTER16x8      2
#define INTER8x16      3
#define P8x8        8
#define I4MB        9
#define I16MB        10
#define IBLOCK        11
#define MAXMODE        13

#define LAMBDA_ACCURACY_BITS    16
#define LAMBDA_FACTOR(lambda)    ((int_32_t) ((double) (1 << LAMBDA_ACCURACY_BITS) * lambda + 0.5))
#define WEIGHTED_COST(factor, bits)  (((factor) * (bits)) >> LAMBDA_ACCURACY_BITS)
#define MV_COST(f, s, cx, cy, px, py)  (WEIGHTED_COST(f, mvbits[((cx) << (s)) - px] + mvbits[((cy) << (s)) - py]))
#define REF_COST(f, ref)    (WEIGHTED_COST(f, refbits[(ref)]))
#define BWD_IDX(ref)      (((ref) < 2) ? 1 - (ref) : (ref))
#define REF_COST_FWD(f, ref)    (WEIGHTED_COST(f, ((img->num_ref_pic_active_fwd_minus1 == 0) ? 0 : refbits[(ref)])))
#define REF_COST_BWD(f, ref)    (WEIGHTED_COST(f, ((img->num_ref_pic_active_bwd_minus1 == 0) ? 0 : BWD_IDX(refbits[ref]))))
#define IS_INTRA(MB)      ((MB)->mb_type == I4MB)
#define IS_INTER(MB)      ((MB)->mb_type != I4MB)
#define IS_INTERMV(MB)      ((MB)->mb_type != I4MB && (MB)->mb_type != 0)
#define IS_DIRECT(MB)      ((MB)->mb_type == 0 && (img->type == B_IMG))
#define IS_COPY(MB)      ((MB)->mb_type == 0 && img->type == INTER_IMG);
#define IS_P8x8(MB)      ((MB)->mb_type == P8x8)
#define MIN_QP        0
#define MAX_QP        63
#define SHIFT_QP      11

/* Picture types */
#define INTRA_IMG  0      /* !< I frame */
#define INTER_IMG  1      /* !< P frame */
#define B_IMG    2      /* !< B frame */

/* Direct Mode types */
#define DIR_TEMPORAL  0      /* !< Temporal Direct Mode */
#define DIR_SPATIAL  1      /* !< Spatial Direct Mode */
#define BLOCK_SIZE  4
#define DCT_BLOCK_SIZE  8
#define MB_BLOCK_SIZE  16
#define BLOCK_MULTIPLE  (MB_BLOCK_SIZE / (2 * BLOCK_SIZE))
#define NO_INTRA_PMODE  5      /* !< #intra prediction modes */

/* !<8x8 intra prediction modes */
#define VERT_PRED  0
#define HOR_PRED  1
#define DC_PRED    2
#define DOWN_LEFT_PRED  3
#define DOWN_RIGHT_PRED 4

/* 8x8 chroma intra prediction modes */
#define DC_PRED_8    0
#define HOR_PRED_8    1
#define VERT_PRED_8    2
#define PLANE_8      3

#define INIT_FRAME_RATE    30
#define EOSEOS      1    /* !< End Of Sequence */

#define MVPRED_MEDIAN    0
#define MVPRED_L    1
#define MVPRED_U    2
#define MVPRED_UR    3

#define MAX_SYMBOLS_PER_MB  1200    /* !< Maximum number of different syntax elements for one MB */

/* CAVLC needs more symbols per MB */
#define MAXPICTURETYPESEQUENCELEN  100  /* !< Maximum size of the string that defines the picture types to be
             * coded, e.g. "IBBPBBPBB" */

/* define _USE_TRANSCODING_SEARCH_RANGE_ */
#define _DISABLE_INTRA_IN_INTER_
#define SVA_START_CODE_EMULATION
#define ZHANG_PENG_TEST

/* end zhang peng */
#ifdef SVA_START_CODE_EMULATION
#define SVA_STREAM_BUF_SIZE  1024    /* must large than 3 */
#endif
#endif