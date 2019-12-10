// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIchrisdIDocumentsdIGenoaWorkdIEdGendIsrcdIdITEGGenDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGElectroReaction.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDecay.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGPhotoReaction.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGOutGEMC.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGEICReaction.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDecElElasticRad.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGGenerator.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGOutput.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGParticle.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDistEScat.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDecTwoBody.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDistribution.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGOutLorentz.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGReaction.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDistDsigDOmega.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGDistDsigDt.h"
#include "/home/chris/Documents/GenoaWork/EdGen/src//TEGOutAll.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_TEGOutput(void *p);
   static void deleteArray_TEGOutput(void *p);
   static void destruct_TEGOutput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGOutput*)
   {
      ::TEGOutput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGOutput >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGOutput", ::TEGOutput::Class_Version(), "TEGOutput.h", 10,
                  typeid(::TEGOutput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGOutput::Dictionary, isa_proxy, 4,
                  sizeof(::TEGOutput) );
      instance.SetDelete(&delete_TEGOutput);
      instance.SetDeleteArray(&deleteArray_TEGOutput);
      instance.SetDestructor(&destruct_TEGOutput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGOutput*)
   {
      return GenerateInitInstanceLocal((::TEGOutput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGOutput*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGGenerator(void *p = 0);
   static void *newArray_TEGGenerator(Long_t size, void *p);
   static void delete_TEGGenerator(void *p);
   static void deleteArray_TEGGenerator(void *p);
   static void destruct_TEGGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGGenerator*)
   {
      ::TEGGenerator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGGenerator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGGenerator", ::TEGGenerator::Class_Version(), "TEGGenerator.h", 20,
                  typeid(::TEGGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGGenerator::Dictionary, isa_proxy, 4,
                  sizeof(::TEGGenerator) );
      instance.SetNew(&new_TEGGenerator);
      instance.SetNewArray(&newArray_TEGGenerator);
      instance.SetDelete(&delete_TEGGenerator);
      instance.SetDeleteArray(&deleteArray_TEGGenerator);
      instance.SetDestructor(&destruct_TEGGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGGenerator*)
   {
      return GenerateInitInstanceLocal((::TEGGenerator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGGenerator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGParticle(void *p = 0);
   static void *newArray_TEGParticle(Long_t size, void *p);
   static void delete_TEGParticle(void *p);
   static void deleteArray_TEGParticle(void *p);
   static void destruct_TEGParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGParticle*)
   {
      ::TEGParticle *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGParticle >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGParticle", ::TEGParticle::Class_Version(), "TEGParticle.h", 21,
                  typeid(::TEGParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGParticle::Dictionary, isa_proxy, 4,
                  sizeof(::TEGParticle) );
      instance.SetNew(&new_TEGParticle);
      instance.SetNewArray(&newArray_TEGParticle);
      instance.SetDelete(&delete_TEGParticle);
      instance.SetDeleteArray(&deleteArray_TEGParticle);
      instance.SetDestructor(&destruct_TEGParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGParticle*)
   {
      return GenerateInitInstanceLocal((::TEGParticle*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGParticle*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDecay(void *p = 0);
   static void *newArray_TEGDecay(Long_t size, void *p);
   static void delete_TEGDecay(void *p);
   static void deleteArray_TEGDecay(void *p);
   static void destruct_TEGDecay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDecay*)
   {
      ::TEGDecay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDecay >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDecay", ::TEGDecay::Class_Version(), "TEGDecay.h", 15,
                  typeid(::TEGDecay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDecay::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDecay) );
      instance.SetNew(&new_TEGDecay);
      instance.SetNewArray(&newArray_TEGDecay);
      instance.SetDelete(&delete_TEGDecay);
      instance.SetDeleteArray(&deleteArray_TEGDecay);
      instance.SetDestructor(&destruct_TEGDecay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDecay*)
   {
      return GenerateInitInstanceLocal((::TEGDecay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDecay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TEGReaction(void *p);
   static void deleteArray_TEGReaction(void *p);
   static void destruct_TEGReaction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGReaction*)
   {
      ::TEGReaction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGReaction >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGReaction", ::TEGReaction::Class_Version(), "TEGReaction.h", 7,
                  typeid(::TEGReaction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGReaction::Dictionary, isa_proxy, 4,
                  sizeof(::TEGReaction) );
      instance.SetDelete(&delete_TEGReaction);
      instance.SetDeleteArray(&deleteArray_TEGReaction);
      instance.SetDestructor(&destruct_TEGReaction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGReaction*)
   {
      return GenerateInitInstanceLocal((::TEGReaction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGReaction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGElectroReaction(void *p = 0);
   static void *newArray_TEGElectroReaction(Long_t size, void *p);
   static void delete_TEGElectroReaction(void *p);
   static void deleteArray_TEGElectroReaction(void *p);
   static void destruct_TEGElectroReaction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGElectroReaction*)
   {
      ::TEGElectroReaction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGElectroReaction >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGElectroReaction", ::TEGElectroReaction::Class_Version(), "TEGElectroReaction.h", 7,
                  typeid(::TEGElectroReaction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGElectroReaction::Dictionary, isa_proxy, 4,
                  sizeof(::TEGElectroReaction) );
      instance.SetNew(&new_TEGElectroReaction);
      instance.SetNewArray(&newArray_TEGElectroReaction);
      instance.SetDelete(&delete_TEGElectroReaction);
      instance.SetDeleteArray(&deleteArray_TEGElectroReaction);
      instance.SetDestructor(&destruct_TEGElectroReaction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGElectroReaction*)
   {
      return GenerateInitInstanceLocal((::TEGElectroReaction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGElectroReaction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGPhotoReaction(void *p = 0);
   static void *newArray_TEGPhotoReaction(Long_t size, void *p);
   static void delete_TEGPhotoReaction(void *p);
   static void deleteArray_TEGPhotoReaction(void *p);
   static void destruct_TEGPhotoReaction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGPhotoReaction*)
   {
      ::TEGPhotoReaction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGPhotoReaction >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGPhotoReaction", ::TEGPhotoReaction::Class_Version(), "TEGPhotoReaction.h", 7,
                  typeid(::TEGPhotoReaction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGPhotoReaction::Dictionary, isa_proxy, 4,
                  sizeof(::TEGPhotoReaction) );
      instance.SetNew(&new_TEGPhotoReaction);
      instance.SetNewArray(&newArray_TEGPhotoReaction);
      instance.SetDelete(&delete_TEGPhotoReaction);
      instance.SetDeleteArray(&deleteArray_TEGPhotoReaction);
      instance.SetDestructor(&destruct_TEGPhotoReaction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGPhotoReaction*)
   {
      return GenerateInitInstanceLocal((::TEGPhotoReaction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGPhotoReaction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGOutGEMC(void *p = 0);
   static void *newArray_TEGOutGEMC(Long_t size, void *p);
   static void delete_TEGOutGEMC(void *p);
   static void deleteArray_TEGOutGEMC(void *p);
   static void destruct_TEGOutGEMC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGOutGEMC*)
   {
      ::TEGOutGEMC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGOutGEMC >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGOutGEMC", ::TEGOutGEMC::Class_Version(), "TEGOutGEMC.h", 11,
                  typeid(::TEGOutGEMC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGOutGEMC::Dictionary, isa_proxy, 4,
                  sizeof(::TEGOutGEMC) );
      instance.SetNew(&new_TEGOutGEMC);
      instance.SetNewArray(&newArray_TEGOutGEMC);
      instance.SetDelete(&delete_TEGOutGEMC);
      instance.SetDeleteArray(&deleteArray_TEGOutGEMC);
      instance.SetDestructor(&destruct_TEGOutGEMC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGOutGEMC*)
   {
      return GenerateInitInstanceLocal((::TEGOutGEMC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGOutGEMC*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGEICReaction(void *p = 0);
   static void *newArray_TEGEICReaction(Long_t size, void *p);
   static void delete_TEGEICReaction(void *p);
   static void deleteArray_TEGEICReaction(void *p);
   static void destruct_TEGEICReaction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGEICReaction*)
   {
      ::TEGEICReaction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGEICReaction >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGEICReaction", ::TEGEICReaction::Class_Version(), "TEGEICReaction.h", 7,
                  typeid(::TEGEICReaction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGEICReaction::Dictionary, isa_proxy, 4,
                  sizeof(::TEGEICReaction) );
      instance.SetNew(&new_TEGEICReaction);
      instance.SetNewArray(&newArray_TEGEICReaction);
      instance.SetDelete(&delete_TEGEICReaction);
      instance.SetDeleteArray(&deleteArray_TEGEICReaction);
      instance.SetDestructor(&destruct_TEGEICReaction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGEICReaction*)
   {
      return GenerateInitInstanceLocal((::TEGEICReaction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGEICReaction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDistribution(void *p = 0);
   static void *newArray_TEGDistribution(Long_t size, void *p);
   static void delete_TEGDistribution(void *p);
   static void deleteArray_TEGDistribution(void *p);
   static void destruct_TEGDistribution(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDistribution*)
   {
      ::TEGDistribution *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDistribution >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDistribution", ::TEGDistribution::Class_Version(), "TEGDistribution.h", 13,
                  typeid(::TEGDistribution), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDistribution::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDistribution) );
      instance.SetNew(&new_TEGDistribution);
      instance.SetNewArray(&newArray_TEGDistribution);
      instance.SetDelete(&delete_TEGDistribution);
      instance.SetDeleteArray(&deleteArray_TEGDistribution);
      instance.SetDestructor(&destruct_TEGDistribution);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDistribution*)
   {
      return GenerateInitInstanceLocal((::TEGDistribution*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDistribution*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDistDsigDOmega(void *p = 0);
   static void *newArray_TEGDistDsigDOmega(Long_t size, void *p);
   static void delete_TEGDistDsigDOmega(void *p);
   static void deleteArray_TEGDistDsigDOmega(void *p);
   static void destruct_TEGDistDsigDOmega(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDistDsigDOmega*)
   {
      ::TEGDistDsigDOmega *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDistDsigDOmega >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDistDsigDOmega", ::TEGDistDsigDOmega::Class_Version(), "TEGDistDsigDOmega.h", 9,
                  typeid(::TEGDistDsigDOmega), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDistDsigDOmega::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDistDsigDOmega) );
      instance.SetNew(&new_TEGDistDsigDOmega);
      instance.SetNewArray(&newArray_TEGDistDsigDOmega);
      instance.SetDelete(&delete_TEGDistDsigDOmega);
      instance.SetDeleteArray(&deleteArray_TEGDistDsigDOmega);
      instance.SetDestructor(&destruct_TEGDistDsigDOmega);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDistDsigDOmega*)
   {
      return GenerateInitInstanceLocal((::TEGDistDsigDOmega*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDistDsigDOmega*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDecElElasticRad(void *p = 0);
   static void *newArray_TEGDecElElasticRad(Long_t size, void *p);
   static void delete_TEGDecElElasticRad(void *p);
   static void deleteArray_TEGDecElElasticRad(void *p);
   static void destruct_TEGDecElElasticRad(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDecElElasticRad*)
   {
      ::TEGDecElElasticRad *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDecElElasticRad >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDecElElasticRad", ::TEGDecElElasticRad::Class_Version(), "TEGDecElElasticRad.h", 8,
                  typeid(::TEGDecElElasticRad), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDecElElasticRad::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDecElElasticRad) );
      instance.SetNew(&new_TEGDecElElasticRad);
      instance.SetNewArray(&newArray_TEGDecElElasticRad);
      instance.SetDelete(&delete_TEGDecElElasticRad);
      instance.SetDeleteArray(&deleteArray_TEGDecElElasticRad);
      instance.SetDestructor(&destruct_TEGDecElElasticRad);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDecElElasticRad*)
   {
      return GenerateInitInstanceLocal((::TEGDecElElasticRad*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDecElElasticRad*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDistEScat(void *p = 0);
   static void *newArray_TEGDistEScat(Long_t size, void *p);
   static void delete_TEGDistEScat(void *p);
   static void deleteArray_TEGDistEScat(void *p);
   static void destruct_TEGDistEScat(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDistEScat*)
   {
      ::TEGDistEScat *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDistEScat >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDistEScat", ::TEGDistEScat::Class_Version(), "TEGDistEScat.h", 11,
                  typeid(::TEGDistEScat), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDistEScat::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDistEScat) );
      instance.SetNew(&new_TEGDistEScat);
      instance.SetNewArray(&newArray_TEGDistEScat);
      instance.SetDelete(&delete_TEGDistEScat);
      instance.SetDeleteArray(&deleteArray_TEGDistEScat);
      instance.SetDestructor(&destruct_TEGDistEScat);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDistEScat*)
   {
      return GenerateInitInstanceLocal((::TEGDistEScat*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDistEScat*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDecTwoBody(void *p = 0);
   static void *newArray_TEGDecTwoBody(Long_t size, void *p);
   static void delete_TEGDecTwoBody(void *p);
   static void deleteArray_TEGDecTwoBody(void *p);
   static void destruct_TEGDecTwoBody(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDecTwoBody*)
   {
      ::TEGDecTwoBody *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDecTwoBody >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDecTwoBody", ::TEGDecTwoBody::Class_Version(), "TEGDecTwoBody.h", 10,
                  typeid(::TEGDecTwoBody), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDecTwoBody::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDecTwoBody) );
      instance.SetNew(&new_TEGDecTwoBody);
      instance.SetNewArray(&newArray_TEGDecTwoBody);
      instance.SetDelete(&delete_TEGDecTwoBody);
      instance.SetDeleteArray(&deleteArray_TEGDecTwoBody);
      instance.SetDestructor(&destruct_TEGDecTwoBody);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDecTwoBody*)
   {
      return GenerateInitInstanceLocal((::TEGDecTwoBody*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDecTwoBody*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGOutLorentz(void *p = 0);
   static void *newArray_TEGOutLorentz(Long_t size, void *p);
   static void delete_TEGOutLorentz(void *p);
   static void deleteArray_TEGOutLorentz(void *p);
   static void destruct_TEGOutLorentz(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGOutLorentz*)
   {
      ::TEGOutLorentz *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGOutLorentz >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGOutLorentz", ::TEGOutLorentz::Class_Version(), "TEGOutLorentz.h", 10,
                  typeid(::TEGOutLorentz), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGOutLorentz::Dictionary, isa_proxy, 4,
                  sizeof(::TEGOutLorentz) );
      instance.SetNew(&new_TEGOutLorentz);
      instance.SetNewArray(&newArray_TEGOutLorentz);
      instance.SetDelete(&delete_TEGOutLorentz);
      instance.SetDeleteArray(&deleteArray_TEGOutLorentz);
      instance.SetDestructor(&destruct_TEGOutLorentz);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGOutLorentz*)
   {
      return GenerateInitInstanceLocal((::TEGOutLorentz*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGOutLorentz*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGDistDsigDt(void *p = 0);
   static void *newArray_TEGDistDsigDt(Long_t size, void *p);
   static void delete_TEGDistDsigDt(void *p);
   static void deleteArray_TEGDistDsigDt(void *p);
   static void destruct_TEGDistDsigDt(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGDistDsigDt*)
   {
      ::TEGDistDsigDt *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGDistDsigDt >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGDistDsigDt", ::TEGDistDsigDt::Class_Version(), "TEGDistDsigDt.h", 8,
                  typeid(::TEGDistDsigDt), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGDistDsigDt::Dictionary, isa_proxy, 4,
                  sizeof(::TEGDistDsigDt) );
      instance.SetNew(&new_TEGDistDsigDt);
      instance.SetNewArray(&newArray_TEGDistDsigDt);
      instance.SetDelete(&delete_TEGDistDsigDt);
      instance.SetDeleteArray(&deleteArray_TEGDistDsigDt);
      instance.SetDestructor(&destruct_TEGDistDsigDt);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGDistDsigDt*)
   {
      return GenerateInitInstanceLocal((::TEGDistDsigDt*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGDistDsigDt*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEGOutAll(void *p = 0);
   static void *newArray_TEGOutAll(Long_t size, void *p);
   static void delete_TEGOutAll(void *p);
   static void deleteArray_TEGOutAll(void *p);
   static void destruct_TEGOutAll(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEGOutAll*)
   {
      ::TEGOutAll *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEGOutAll >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEGOutAll", ::TEGOutAll::Class_Version(), "TEGOutAll.h", 12,
                  typeid(::TEGOutAll), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEGOutAll::Dictionary, isa_proxy, 4,
                  sizeof(::TEGOutAll) );
      instance.SetNew(&new_TEGOutAll);
      instance.SetNewArray(&newArray_TEGOutAll);
      instance.SetDelete(&delete_TEGOutAll);
      instance.SetDeleteArray(&deleteArray_TEGOutAll);
      instance.SetDestructor(&destruct_TEGOutAll);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEGOutAll*)
   {
      return GenerateInitInstanceLocal((::TEGOutAll*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEGOutAll*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TEGOutput::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGOutput::Class_Name()
{
   return "TEGOutput";
}

//______________________________________________________________________________
const char *TEGOutput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutput*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGOutput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutput*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGOutput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutput*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGOutput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutput*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGGenerator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGGenerator::Class_Name()
{
   return "TEGGenerator";
}

//______________________________________________________________________________
const char *TEGGenerator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGGenerator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGGenerator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGGenerator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGGenerator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGGenerator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGGenerator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGGenerator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGParticle::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGParticle::Class_Name()
{
   return "TEGParticle";
}

//______________________________________________________________________________
const char *TEGParticle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGParticle*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGParticle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGParticle*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGParticle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGParticle*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGParticle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGParticle*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDecay::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDecay::Class_Name()
{
   return "TEGDecay";
}

//______________________________________________________________________________
const char *TEGDecay::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecay*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDecay::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecay*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDecay::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecay*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDecay::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecay*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGReaction::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGReaction::Class_Name()
{
   return "TEGReaction";
}

//______________________________________________________________________________
const char *TEGReaction::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGReaction*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGReaction::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGReaction*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGReaction::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGReaction*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGReaction::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGReaction*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGElectroReaction::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGElectroReaction::Class_Name()
{
   return "TEGElectroReaction";
}

//______________________________________________________________________________
const char *TEGElectroReaction::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGElectroReaction*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGElectroReaction::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGElectroReaction*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGElectroReaction::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGElectroReaction*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGElectroReaction::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGElectroReaction*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGPhotoReaction::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGPhotoReaction::Class_Name()
{
   return "TEGPhotoReaction";
}

//______________________________________________________________________________
const char *TEGPhotoReaction::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGPhotoReaction*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGPhotoReaction::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGPhotoReaction*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGPhotoReaction::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGPhotoReaction*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGPhotoReaction::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGPhotoReaction*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGOutGEMC::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGOutGEMC::Class_Name()
{
   return "TEGOutGEMC";
}

//______________________________________________________________________________
const char *TEGOutGEMC::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutGEMC*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGOutGEMC::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutGEMC*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGOutGEMC::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutGEMC*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGOutGEMC::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutGEMC*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGEICReaction::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGEICReaction::Class_Name()
{
   return "TEGEICReaction";
}

//______________________________________________________________________________
const char *TEGEICReaction::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGEICReaction*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGEICReaction::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGEICReaction*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGEICReaction::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGEICReaction*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGEICReaction::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGEICReaction*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDistribution::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDistribution::Class_Name()
{
   return "TEGDistribution";
}

//______________________________________________________________________________
const char *TEGDistribution::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistribution*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDistribution::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistribution*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDistribution::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistribution*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDistribution::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistribution*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDistDsigDOmega::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDistDsigDOmega::Class_Name()
{
   return "TEGDistDsigDOmega";
}

//______________________________________________________________________________
const char *TEGDistDsigDOmega::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDOmega*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDistDsigDOmega::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDOmega*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDistDsigDOmega::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDOmega*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDistDsigDOmega::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDOmega*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDecElElasticRad::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDecElElasticRad::Class_Name()
{
   return "TEGDecElElasticRad";
}

//______________________________________________________________________________
const char *TEGDecElElasticRad::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecElElasticRad*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDecElElasticRad::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecElElasticRad*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDecElElasticRad::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecElElasticRad*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDecElElasticRad::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecElElasticRad*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDistEScat::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDistEScat::Class_Name()
{
   return "TEGDistEScat";
}

//______________________________________________________________________________
const char *TEGDistEScat::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistEScat*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDistEScat::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistEScat*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDistEScat::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistEScat*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDistEScat::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistEScat*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDecTwoBody::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDecTwoBody::Class_Name()
{
   return "TEGDecTwoBody";
}

//______________________________________________________________________________
const char *TEGDecTwoBody::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecTwoBody*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDecTwoBody::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDecTwoBody*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDecTwoBody::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecTwoBody*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDecTwoBody::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDecTwoBody*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGOutLorentz::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGOutLorentz::Class_Name()
{
   return "TEGOutLorentz";
}

//______________________________________________________________________________
const char *TEGOutLorentz::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutLorentz*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGOutLorentz::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutLorentz*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGOutLorentz::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutLorentz*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGOutLorentz::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutLorentz*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGDistDsigDt::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGDistDsigDt::Class_Name()
{
   return "TEGDistDsigDt";
}

//______________________________________________________________________________
const char *TEGDistDsigDt::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDt*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGDistDsigDt::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDt*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGDistDsigDt::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDt*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGDistDsigDt::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGDistDsigDt*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEGOutAll::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEGOutAll::Class_Name()
{
   return "TEGOutAll";
}

//______________________________________________________________________________
const char *TEGOutAll::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutAll*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEGOutAll::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEGOutAll*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEGOutAll::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutAll*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEGOutAll::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEGOutAll*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TEGOutput::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGOutput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGOutput::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGOutput::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TEGOutput(void *p) {
      delete ((::TEGOutput*)p);
   }
   static void deleteArray_TEGOutput(void *p) {
      delete [] ((::TEGOutput*)p);
   }
   static void destruct_TEGOutput(void *p) {
      typedef ::TEGOutput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGOutput

//______________________________________________________________________________
void TEGGenerator::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGGenerator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGGenerator::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGGenerator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGGenerator(void *p) {
      return  p ? new(p) ::TEGGenerator : new ::TEGGenerator;
   }
   static void *newArray_TEGGenerator(Long_t nElements, void *p) {
      return p ? new(p) ::TEGGenerator[nElements] : new ::TEGGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGGenerator(void *p) {
      delete ((::TEGGenerator*)p);
   }
   static void deleteArray_TEGGenerator(void *p) {
      delete [] ((::TEGGenerator*)p);
   }
   static void destruct_TEGGenerator(void *p) {
      typedef ::TEGGenerator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGGenerator

//______________________________________________________________________________
void TEGParticle::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGParticle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGParticle::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGParticle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGParticle(void *p) {
      return  p ? new(p) ::TEGParticle : new ::TEGParticle;
   }
   static void *newArray_TEGParticle(Long_t nElements, void *p) {
      return p ? new(p) ::TEGParticle[nElements] : new ::TEGParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGParticle(void *p) {
      delete ((::TEGParticle*)p);
   }
   static void deleteArray_TEGParticle(void *p) {
      delete [] ((::TEGParticle*)p);
   }
   static void destruct_TEGParticle(void *p) {
      typedef ::TEGParticle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGParticle

//______________________________________________________________________________
void TEGDecay::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDecay.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDecay::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDecay::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDecay(void *p) {
      return  p ? new(p) ::TEGDecay : new ::TEGDecay;
   }
   static void *newArray_TEGDecay(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDecay[nElements] : new ::TEGDecay[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDecay(void *p) {
      delete ((::TEGDecay*)p);
   }
   static void deleteArray_TEGDecay(void *p) {
      delete [] ((::TEGDecay*)p);
   }
   static void destruct_TEGDecay(void *p) {
      typedef ::TEGDecay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDecay

//______________________________________________________________________________
void TEGReaction::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGReaction.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGReaction::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGReaction::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TEGReaction(void *p) {
      delete ((::TEGReaction*)p);
   }
   static void deleteArray_TEGReaction(void *p) {
      delete [] ((::TEGReaction*)p);
   }
   static void destruct_TEGReaction(void *p) {
      typedef ::TEGReaction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGReaction

//______________________________________________________________________________
void TEGElectroReaction::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGElectroReaction.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGElectroReaction::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGElectroReaction::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGElectroReaction(void *p) {
      return  p ? new(p) ::TEGElectroReaction : new ::TEGElectroReaction;
   }
   static void *newArray_TEGElectroReaction(Long_t nElements, void *p) {
      return p ? new(p) ::TEGElectroReaction[nElements] : new ::TEGElectroReaction[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGElectroReaction(void *p) {
      delete ((::TEGElectroReaction*)p);
   }
   static void deleteArray_TEGElectroReaction(void *p) {
      delete [] ((::TEGElectroReaction*)p);
   }
   static void destruct_TEGElectroReaction(void *p) {
      typedef ::TEGElectroReaction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGElectroReaction

//______________________________________________________________________________
void TEGPhotoReaction::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGPhotoReaction.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGPhotoReaction::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGPhotoReaction::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGPhotoReaction(void *p) {
      return  p ? new(p) ::TEGPhotoReaction : new ::TEGPhotoReaction;
   }
   static void *newArray_TEGPhotoReaction(Long_t nElements, void *p) {
      return p ? new(p) ::TEGPhotoReaction[nElements] : new ::TEGPhotoReaction[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGPhotoReaction(void *p) {
      delete ((::TEGPhotoReaction*)p);
   }
   static void deleteArray_TEGPhotoReaction(void *p) {
      delete [] ((::TEGPhotoReaction*)p);
   }
   static void destruct_TEGPhotoReaction(void *p) {
      typedef ::TEGPhotoReaction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGPhotoReaction

//______________________________________________________________________________
void TEGOutGEMC::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGOutGEMC.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGOutGEMC::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGOutGEMC::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGOutGEMC(void *p) {
      return  p ? new(p) ::TEGOutGEMC : new ::TEGOutGEMC;
   }
   static void *newArray_TEGOutGEMC(Long_t nElements, void *p) {
      return p ? new(p) ::TEGOutGEMC[nElements] : new ::TEGOutGEMC[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGOutGEMC(void *p) {
      delete ((::TEGOutGEMC*)p);
   }
   static void deleteArray_TEGOutGEMC(void *p) {
      delete [] ((::TEGOutGEMC*)p);
   }
   static void destruct_TEGOutGEMC(void *p) {
      typedef ::TEGOutGEMC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGOutGEMC

//______________________________________________________________________________
void TEGEICReaction::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGEICReaction.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGEICReaction::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGEICReaction::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGEICReaction(void *p) {
      return  p ? new(p) ::TEGEICReaction : new ::TEGEICReaction;
   }
   static void *newArray_TEGEICReaction(Long_t nElements, void *p) {
      return p ? new(p) ::TEGEICReaction[nElements] : new ::TEGEICReaction[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGEICReaction(void *p) {
      delete ((::TEGEICReaction*)p);
   }
   static void deleteArray_TEGEICReaction(void *p) {
      delete [] ((::TEGEICReaction*)p);
   }
   static void destruct_TEGEICReaction(void *p) {
      typedef ::TEGEICReaction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGEICReaction

//______________________________________________________________________________
void TEGDistribution::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDistribution.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDistribution::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDistribution::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDistribution(void *p) {
      return  p ? new(p) ::TEGDistribution : new ::TEGDistribution;
   }
   static void *newArray_TEGDistribution(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDistribution[nElements] : new ::TEGDistribution[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDistribution(void *p) {
      delete ((::TEGDistribution*)p);
   }
   static void deleteArray_TEGDistribution(void *p) {
      delete [] ((::TEGDistribution*)p);
   }
   static void destruct_TEGDistribution(void *p) {
      typedef ::TEGDistribution current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDistribution

//______________________________________________________________________________
void TEGDistDsigDOmega::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDistDsigDOmega.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDistDsigDOmega::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDistDsigDOmega::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDistDsigDOmega(void *p) {
      return  p ? new(p) ::TEGDistDsigDOmega : new ::TEGDistDsigDOmega;
   }
   static void *newArray_TEGDistDsigDOmega(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDistDsigDOmega[nElements] : new ::TEGDistDsigDOmega[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDistDsigDOmega(void *p) {
      delete ((::TEGDistDsigDOmega*)p);
   }
   static void deleteArray_TEGDistDsigDOmega(void *p) {
      delete [] ((::TEGDistDsigDOmega*)p);
   }
   static void destruct_TEGDistDsigDOmega(void *p) {
      typedef ::TEGDistDsigDOmega current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDistDsigDOmega

//______________________________________________________________________________
void TEGDecElElasticRad::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDecElElasticRad.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDecElElasticRad::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDecElElasticRad::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDecElElasticRad(void *p) {
      return  p ? new(p) ::TEGDecElElasticRad : new ::TEGDecElElasticRad;
   }
   static void *newArray_TEGDecElElasticRad(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDecElElasticRad[nElements] : new ::TEGDecElElasticRad[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDecElElasticRad(void *p) {
      delete ((::TEGDecElElasticRad*)p);
   }
   static void deleteArray_TEGDecElElasticRad(void *p) {
      delete [] ((::TEGDecElElasticRad*)p);
   }
   static void destruct_TEGDecElElasticRad(void *p) {
      typedef ::TEGDecElElasticRad current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDecElElasticRad

//______________________________________________________________________________
void TEGDistEScat::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDistEScat.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDistEScat::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDistEScat::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDistEScat(void *p) {
      return  p ? new(p) ::TEGDistEScat : new ::TEGDistEScat;
   }
   static void *newArray_TEGDistEScat(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDistEScat[nElements] : new ::TEGDistEScat[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDistEScat(void *p) {
      delete ((::TEGDistEScat*)p);
   }
   static void deleteArray_TEGDistEScat(void *p) {
      delete [] ((::TEGDistEScat*)p);
   }
   static void destruct_TEGDistEScat(void *p) {
      typedef ::TEGDistEScat current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDistEScat

//______________________________________________________________________________
void TEGDecTwoBody::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDecTwoBody.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDecTwoBody::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDecTwoBody::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDecTwoBody(void *p) {
      return  p ? new(p) ::TEGDecTwoBody : new ::TEGDecTwoBody;
   }
   static void *newArray_TEGDecTwoBody(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDecTwoBody[nElements] : new ::TEGDecTwoBody[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDecTwoBody(void *p) {
      delete ((::TEGDecTwoBody*)p);
   }
   static void deleteArray_TEGDecTwoBody(void *p) {
      delete [] ((::TEGDecTwoBody*)p);
   }
   static void destruct_TEGDecTwoBody(void *p) {
      typedef ::TEGDecTwoBody current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDecTwoBody

//______________________________________________________________________________
void TEGOutLorentz::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGOutLorentz.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGOutLorentz::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGOutLorentz::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGOutLorentz(void *p) {
      return  p ? new(p) ::TEGOutLorentz : new ::TEGOutLorentz;
   }
   static void *newArray_TEGOutLorentz(Long_t nElements, void *p) {
      return p ? new(p) ::TEGOutLorentz[nElements] : new ::TEGOutLorentz[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGOutLorentz(void *p) {
      delete ((::TEGOutLorentz*)p);
   }
   static void deleteArray_TEGOutLorentz(void *p) {
      delete [] ((::TEGOutLorentz*)p);
   }
   static void destruct_TEGOutLorentz(void *p) {
      typedef ::TEGOutLorentz current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGOutLorentz

//______________________________________________________________________________
void TEGDistDsigDt::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGDistDsigDt.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGDistDsigDt::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGDistDsigDt::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGDistDsigDt(void *p) {
      return  p ? new(p) ::TEGDistDsigDt : new ::TEGDistDsigDt;
   }
   static void *newArray_TEGDistDsigDt(Long_t nElements, void *p) {
      return p ? new(p) ::TEGDistDsigDt[nElements] : new ::TEGDistDsigDt[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGDistDsigDt(void *p) {
      delete ((::TEGDistDsigDt*)p);
   }
   static void deleteArray_TEGDistDsigDt(void *p) {
      delete [] ((::TEGDistDsigDt*)p);
   }
   static void destruct_TEGDistDsigDt(void *p) {
      typedef ::TEGDistDsigDt current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGDistDsigDt

//______________________________________________________________________________
void TEGOutAll::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEGOutAll.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEGOutAll::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEGOutAll::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEGOutAll(void *p) {
      return  p ? new(p) ::TEGOutAll : new ::TEGOutAll;
   }
   static void *newArray_TEGOutAll(Long_t nElements, void *p) {
      return p ? new(p) ::TEGOutAll[nElements] : new ::TEGOutAll[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEGOutAll(void *p) {
      delete ((::TEGOutAll*)p);
   }
   static void deleteArray_TEGOutAll(void *p) {
      delete [] ((::TEGOutAll*)p);
   }
   static void destruct_TEGOutAll(void *p) {
      typedef ::TEGOutAll current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TEGOutAll

namespace {
  void TriggerDictionaryInitialization_TEGGenDict_Impl() {
    static const char* headers[] = {
"src//TEGElectroReaction.h",
"src//TEGDecay.h",
"src//TEGPhotoReaction.h",
"src//TEGOutGEMC.h",
"src//TEGEICReaction.h",
"src//TEGDecElElasticRad.h",
"src//TEGGenerator.h",
"src//TEGOutput.h",
"src//TEGParticle.h",
"src//TEGDistEScat.h",
"src//TEGDecTwoBody.h",
"src//TEGDistribution.h",
"src//TEGOutLorentz.h",
"src//TEGReaction.h",
"src//TEGDistDsigDOmega.h",
"src//TEGDistDsigDt.h",
"src//TEGOutAll.h",
0
    };
    static const char* includePaths[] = {
"/home/chris/Documents/GenoaWork/EdGen/src/",
"/home/chris/Documents/PhD/root/root/include",
"/home/chris/Documents/PhD/root/root/include",
"/home/chris/Documents/GenoaWork/EdGen/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TEGGenDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TEGOutput.h")))  __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGOutput;
class __attribute__((annotate("$clingAutoload$TEGGenerator.h")))  __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGGenerator;
class __attribute__((annotate("$clingAutoload$TEGParticle.h")))  __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGParticle;
class __attribute__((annotate("$clingAutoload$TEGDecay.h")))  __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGDecay;
class __attribute__((annotate("$clingAutoload$TEGReaction.h")))  __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGReaction;
class __attribute__((annotate("$clingAutoload$src//TEGElectroReaction.h")))  TEGElectroReaction;
class __attribute__((annotate("$clingAutoload$src//TEGPhotoReaction.h")))  TEGPhotoReaction;
class __attribute__((annotate("$clingAutoload$src//TEGOutGEMC.h")))  TEGOutGEMC;
class __attribute__((annotate("$clingAutoload$src//TEGEICReaction.h")))  TEGEICReaction;
class __attribute__((annotate("$clingAutoload$TEGDistribution.h")))  __attribute__((annotate("$clingAutoload$src//TEGDecElElasticRad.h")))  TEGDistribution;
class __attribute__((annotate("$clingAutoload$TEGDistDsigDOmega.h")))  __attribute__((annotate("$clingAutoload$src//TEGDecElElasticRad.h")))  TEGDistDsigDOmega;
class __attribute__((annotate("$clingAutoload$src//TEGDecElElasticRad.h")))  TEGDecElElasticRad;
class __attribute__((annotate("$clingAutoload$src//TEGDistEScat.h")))  TEGDistEScat;
class __attribute__((annotate("$clingAutoload$src//TEGDecTwoBody.h")))  TEGDecTwoBody;
class __attribute__((annotate("$clingAutoload$src//TEGOutLorentz.h")))  TEGOutLorentz;
class __attribute__((annotate("$clingAutoload$src//TEGDistDsigDt.h")))  TEGDistDsigDt;
class __attribute__((annotate("$clingAutoload$src//TEGOutAll.h")))  TEGOutAll;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TEGGenDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "src//TEGElectroReaction.h"
#include "src//TEGDecay.h"
#include "src//TEGPhotoReaction.h"
#include "src//TEGOutGEMC.h"
#include "src//TEGEICReaction.h"
#include "src//TEGDecElElasticRad.h"
#include "src//TEGGenerator.h"
#include "src//TEGOutput.h"
#include "src//TEGParticle.h"
#include "src//TEGDistEScat.h"
#include "src//TEGDecTwoBody.h"
#include "src//TEGDistribution.h"
#include "src//TEGOutLorentz.h"
#include "src//TEGReaction.h"
#include "src//TEGDistDsigDOmega.h"
#include "src//TEGDistDsigDt.h"
#include "src//TEGOutAll.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TEGDecElElasticRad", payloadCode, "@",
"TEGDecTwoBody", payloadCode, "@",
"TEGDecay", payloadCode, "@",
"TEGDistDsigDOmega", payloadCode, "@",
"TEGDistDsigDt", payloadCode, "@",
"TEGDistEScat", payloadCode, "@",
"TEGDistribution", payloadCode, "@",
"TEGEICReaction", payloadCode, "@",
"TEGElectroReaction", payloadCode, "@",
"TEGGenerator", payloadCode, "@",
"TEGOutAll", payloadCode, "@",
"TEGOutGEMC", payloadCode, "@",
"TEGOutLorentz", payloadCode, "@",
"TEGOutput", payloadCode, "@",
"TEGParticle", payloadCode, "@",
"TEGPhotoReaction", payloadCode, "@",
"TEGReaction", payloadCode, "@",
"gEGRandom", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TEGGenDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TEGGenDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TEGGenDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TEGGenDict() {
  TriggerDictionaryInitialization_TEGGenDict_Impl();
}
