#include "DSP_Instruction.h"

int DSP_LOOP(int icurrent, int loopstart, int loopend)
{
    if(icurrent >= loopend)
    {
        return icurrent+loopstart-loopend;
    }
    else
    {
        return icurrent;
    }
}

int DSP_MUL(int dsp24bit1, int dsp24bit2)
{
    dsp24bit1/=256;//16bit signed
    dsp24bit2/=256;//16bit signed
    dsp24bit1*=dsp24bit2;//31bit signed
    return int(dsp24bit1/128);
}

void DSP_EG(STR_DSP_EG *pEG)
{
    pEG->iLevel = pEG->iLevel+pEG->iRate;

    if(pEG->iRate >= 0)
    {
        if(pEG->iLevel > pEG->iTarget)
        {
            pEG->iLevel = pEG->iTarget;
        }
    }
    else
    {
        if(pEG->iLevel < pEG->iTarget)
        {
            pEG->iLevel = pEG->iTarget;
        }
    }
}

#define MAX_SAMPLE_BITS 24

int DoLineInterpolation(int val1, int val2, int iFracAddr)
{
    //val1 and val2 is 16bit signed value. iFracAddr is 16bit signed value.
    val2 -= val1;
    val2 *= iFracAddr;
    val1 <<= (MAX_SAMPLE_BITS-16);
    val2 >>= (32-MAX_SAMPLE_BITS);
    return val1+val2;
}