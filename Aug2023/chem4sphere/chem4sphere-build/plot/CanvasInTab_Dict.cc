// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIdthompsondIAug2023dIchem4spheredIchem4spheremIbuilddIplotdICanvasInTab_Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
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

// Header files passed as explicit arguments
#include "/home/dthompson/Aug2023/chem4sphere/plot/include/CanvasInTab.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void delete_CanvasInTab(void *p);
   static void deleteArray_CanvasInTab(void *p);
   static void destruct_CanvasInTab(void *p);
   static void streamer_CanvasInTab(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CanvasInTab*)
   {
      ::CanvasInTab *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CanvasInTab >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CanvasInTab", ::CanvasInTab::Class_Version(), "", 36,
                  typeid(::CanvasInTab), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CanvasInTab::Dictionary, isa_proxy, 16,
                  sizeof(::CanvasInTab) );
      instance.SetDelete(&delete_CanvasInTab);
      instance.SetDeleteArray(&deleteArray_CanvasInTab);
      instance.SetDestructor(&destruct_CanvasInTab);
      instance.SetStreamerFunc(&streamer_CanvasInTab);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CanvasInTab*)
   {
      return GenerateInitInstanceLocal(static_cast<::CanvasInTab*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CanvasInTab*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CanvasInTab::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CanvasInTab::Class_Name()
{
   return "CanvasInTab";
}

//______________________________________________________________________________
const char *CanvasInTab::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CanvasInTab*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CanvasInTab::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CanvasInTab*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CanvasInTab::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CanvasInTab*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CanvasInTab::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CanvasInTab*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CanvasInTab::Streamer(TBuffer &R__b)
{
   // Stream an object of class CanvasInTab.

   TGMainFrame::Streamer(R__b);
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CanvasInTab(void *p) {
      delete (static_cast<::CanvasInTab*>(p));
   }
   static void deleteArray_CanvasInTab(void *p) {
      delete [] (static_cast<::CanvasInTab*>(p));
   }
   static void destruct_CanvasInTab(void *p) {
      typedef ::CanvasInTab current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_CanvasInTab(TBuffer &buf, void *obj) {
      ((::CanvasInTab*)obj)->::CanvasInTab::Streamer(buf);
   }
} // end of namespace ROOT for class ::CanvasInTab

namespace {
  void TriggerDictionaryInitialization_CanvasInTab_Dict_Impl() {
    static const char* headers[] = {
"/home/dthompson/Aug2023/chem4sphere/plot/include/CanvasInTab.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/dthompson/root-6.28.02-install/include/",
"/home/dthompson/Aug2023/chem4sphere/chem4sphere-build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CanvasInTab_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/home/dthompson/Aug2023/chem4sphere/plot/include/CanvasInTab.hh")))  CanvasInTab;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CanvasInTab_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/dthompson/Aug2023/chem4sphere/plot/include/CanvasInTab.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CanvasInTab", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CanvasInTab_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CanvasInTab_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CanvasInTab_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CanvasInTab_Dict() {
  TriggerDictionaryInitialization_CanvasInTab_Dict_Impl();
}
