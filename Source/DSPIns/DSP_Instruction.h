#ifndef DSP_INSTRUCTION_H_INCLUDE
#define DSP_INSTRUCTION_H_INCLUDE

//模拟DSP指令的函数

typedef struct _STR_DSP_EG
{
    int iLevel;
    int iRate;
    int iTarget;
}STR_DSP_EG;

int DSP_LOOP(int icurrent, int loopstart, int loopend);
int DSP_MUL(int dsp24bit1, int dsp24bit2);
void DSP_EG(STR_DSP_EG *pEG);

//return 24bit signed value.
int DoLineInterpolation(int val1, int val2, int iFracAddr);

#endif