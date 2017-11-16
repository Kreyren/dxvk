#pragma once

#include "dxbc_gen_common.h"

namespace dxvk {
  
  /**
   * \brief Pixel shader code generator
   */
  class DxbcPsCodeGen : public DxbcCodeGen {
    
  public:
    
    DxbcPsCodeGen();
    ~DxbcPsCodeGen();
    
    void dclInterfaceVar(
            DxbcOperandType   regType,
            uint32_t          regId,
            uint32_t          regDim,
            DxbcComponentMask regMask,
            DxbcSystemValue   sv);
    
    DxbcPointer ptrInterfaceVar(
            DxbcOperandType   regType,
            uint32_t          regId);
    
    DxbcPointer ptrInterfaceVarIndexed(
            DxbcOperandType   regType,
            uint32_t          regId,
      const DxbcValue&        index);
    
    Rc<DxvkShader> finalize() final;
    
  private:
    
    uint32_t m_function = 0;
    
    DxbcPointer m_svPosition;
    
    std::array<DxbcPointer, 32> m_vRegs;
    std::array<DxbcPointer, 32> m_vRegsSv;
    std::array<DxbcPointer, 32> m_oRegs;
    
    std::vector<DxbcSvMapping> m_svInputs;
    
    void prepareSvInputs();
    void prepareSvOutputs();
    
  };
  
}