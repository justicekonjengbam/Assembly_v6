#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif




template <typename R, typename T1>
struct ConstrainedFuncInvoker1;
template <typename R, typename T1>
struct ConstrainedFuncInvoker1<R, T1*>
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, params, &ret);
		return ret;
	}
};

struct Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722;
struct ConditionalWeakTable_2_t87BE12792DC61EC9AE17609EC1ACA0671B3F5605;
struct ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F;
struct Dictionary_2_tF8C88C2A1FA068ADD1A1529DE03E50399F166007;
struct List_1_t10898B3F76B071D9912E09793660EC44AB6BB82C;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct EphemeronU5BU5D_t4F80428A1142C3102C946127F8190063001742E8;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EventWaitHandle_t18F2EB0161747B0646A9A406015A61A214A1EB7E;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct MethodInfo_t;
struct String_t;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C;
struct UnsafeQueueBlockPoolData_tA87D4984A1174C6ADB32EBF1E560F473D99280F0;
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303;
struct MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970;
struct TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C;

IL2CPP_EXTERN_C RuntimeClass* NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C const RuntimeMethod* ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F  : public RuntimeObject
{
	EphemeronU5BU5D_t4F80428A1142C3102C946127F8190063001742E8* ___data;
	RuntimeObject* ____lock;
	int32_t ___size;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90  : public RuntimeObject
{
};
struct Avx2_tEF5390382630DE33677921890832DA46CE372FBC  : public RuntimeObject
{
};
struct MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970  : public RuntimeObject
{
	int32_t ___myLock;
	int32_t ___owners;
	uint32_t ___numWriteWaiters;
	uint32_t ___numReadWaiters;
	EventWaitHandle_t18F2EB0161747B0646A9A406015A61A214A1EB7E* ___writeEvent;
	EventWaitHandle_t18F2EB0161747B0646A9A406015A61A214A1EB7E* ___readEvent;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B 
{
	uint64_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t* ___values;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t* ___values_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keys_OffsetPadding[8];
			uint8_t* ___keys;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keys_OffsetPadding_forAlignmentOnly[8];
			uint8_t* ___keys_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___next_OffsetPadding[16];
			uint8_t* ___next;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___next_OffsetPadding_forAlignmentOnly[16];
			uint8_t* ___next_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___buckets_OffsetPadding[24];
			uint8_t* ___buckets;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___buckets_OffsetPadding_forAlignmentOnly[24];
			uint8_t* ___buckets_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keyCapacity_OffsetPadding[32];
			int32_t ___keyCapacity;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keyCapacity_OffsetPadding_forAlignmentOnly[32];
			int32_t ___keyCapacity_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding[36];
			int32_t ___bucketCapacityMask;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding_forAlignmentOnly[36];
			int32_t ___bucketCapacityMask_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding[40];
			int32_t ___allocatedIndexLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding_forAlignmentOnly[40];
			int32_t ___allocatedIndexLength_forAlignmentOnly;
		};
	};
};
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C 
{
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___m_NextBlock;
	int32_t ___m_NumItems;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 
{
	int64_t ___m_long;
};
struct Array_t3B8F006A80A48C83471DE3516556F1AFE6873381 
{
	union
	{
		struct
		{
		};
		uint8_t Array_t3B8F006A80A48C83471DE3516556F1AFE6873381__padding[1];
	};
};
struct EventCacheKey_t808E4964CFCF655710626DE6089FAF2C53DDECC9 
{
	RuntimeObject* ___target;
	MethodInfo_t* ___method;
};
struct EventCacheKey_t808E4964CFCF655710626DE6089FAF2C53DDECC9_marshaled_pinvoke
{
	Il2CppIUnknown* ___target;
	MethodInfo_t* ___method;
};
struct EventCacheKey_t808E4964CFCF655710626DE6089FAF2C53DDECC9_marshaled_com
{
	Il2CppIUnknown* ___target;
	MethodInfo_t* ___method;
};
struct HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B 
{
	uint8_t* ___Ptr;
	int32_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	UnsafeQueueBlockPoolData_tA87D4984A1174C6ADB32EBF1E560F473D99280F0* ___m_QueuePool;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6 
{
	int32_t* ___Ptr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___m_Capacity;
	int32_t ___m_Filled;
	int32_t ___m_Write;
	int32_t ___m_Read;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 
{
	uint64_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 
{
	intptr_t ___m_FirstBlock;
	intptr_t ___m_LastBlock;
	int32_t ___m_MaxItems;
	int32_t ___m_CurrentRead;
	uint8_t* ___m_CurrentWriteBlockTLS;
};
struct UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 
{
	void* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84 
{
	uint8_t* ___m_pointer;
	int64_t ___m_bytes;
	Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 ___m_union;
};
struct EventRegistrationTokenList_t2B404250C277B1746BAA0E028B10FCEFEE3E0E7C 
{
	EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___firstToken;
	List_1_t10898B3F76B071D9912E09793660EC44AB6BB82C* ___restTokens;
};
struct EventRegistrationTokenList_t2B404250C277B1746BAA0E028B10FCEFEE3E0E7C_marshaled_pinvoke
{
	EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___firstToken;
	List_1_t10898B3F76B071D9912E09793660EC44AB6BB82C* ___restTokens;
};
struct EventRegistrationTokenList_t2B404250C277B1746BAA0E028B10FCEFEE3E0E7C_marshaled_com
{
	EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___firstToken;
	List_1_t10898B3F76B071D9912E09793660EC44AB6BB82C* ___restTokens;
};
struct TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C  : public RuntimeObject
{
	int32_t ____count;
	EventCacheKey_t808E4964CFCF655710626DE6089FAF2C53DDECC9 ____key;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 
{
	UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 ___m_UntypedListData;
};
struct EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303  : public RuntimeObject
{
	TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C* ____tokenListCount;
	EventRegistrationTokenList_t2B404250C277B1746BAA0E028B10FCEFEE3E0E7C ____tokenList;
};
struct Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722  : public MulticastDelegate_t
{
};
struct NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_StaticFields
{
	Dictionary_2_tF8C88C2A1FA068ADD1A1529DE03E50399F166007* ___s_eventRegistrations;
	MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* ___s_eventCacheRWLock;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ConditionalWeakTable_2_FindEquivalentKeyUnsafe_m2A6C83594FE9026A5E0F88CEDFCB70681C798284_gshared (ConditionalWeakTable_2_t87BE12792DC61EC9AE17609EC1ACA0671B3F5605* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ConditionalWeakTable_2_Remove_m51E45FAFE5B1D6E9FDA123477422367F1F215DE6_gshared (ConditionalWeakTable_2_t87BE12792DC61EC9AE17609EC1ACA0671B3F5605* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_gshared_inline (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* __this, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___0_obj, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* NativeOrStaticEventRegistrationImpl_GetInstanceKey_m36F73D84E7D3A302C2C8E3ACECB7E49866CF4C1C (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* ___0_removeMethod, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MyReaderWriterLock_AcquireReaderLock_m96E5ECF7E8F7635E7518D8882FE7FA304EC9309D (MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* __this, int32_t ___0_millisecondsTimeout, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MyReaderWriterLock_ReleaseReaderLock_m00DB66CED452771CBBFED2BCD55730C9767F2ADE (MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* NativeOrStaticEventRegistrationImpl_GetEventRegistrationTokenTableNoCreate_m580A1FCAB05541DBBE8CDD6574621D8F9D8EBF9C (RuntimeObject* ___0_instance, Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* ___1_removeMethod, TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C** ___2_tokenListCount, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Monitor_Exit_m05B2CF037E2214B3208198C282490A2A475653FA (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Monitor_Enter_m3CDB589DA1300B513D55FDCFB52B63E879794149 (RuntimeObject* ___0_obj, bool* ___1_lockTaken, const RuntimeMethod* method) ;
inline RuntimeObject* ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E (ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* __this, RuntimeObject* ___0_key, EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303** ___1_value, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F*, RuntimeObject*, EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303**, const RuntimeMethod*))ConditionalWeakTable_2_FindEquivalentKeyUnsafe_m2A6C83594FE9026A5E0F88CEDFCB70681C798284_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventRegistrationTokenListWithCount_Pop_mD9C29E40F98D1A20AAF83702169F1A0CB11E750D (EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* __this, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B* ___0_token, const RuntimeMethod* method) ;
inline bool ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698 (ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F*, RuntimeObject*, const RuntimeMethod*))ConditionalWeakTable_2_Remove_m51E45FAFE5B1D6E9FDA123477422367F1F215DE6_gshared)(__this, ___0_key, method);
}
inline void Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_inline (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* __this, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722*, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B, const RuntimeMethod*))Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_gshared_inline)(__this, ___0_obj, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586 (int32_t* __this, int32_t ___0_value, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380 (void* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, int64_t ___4_size, int32_t ___5_align, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeOrStaticEventRegistrationImpl_RemoveEventHandler_TisRuntimeObject_m2957870D137C66E98FB0B12CCD65C32884C0D623_gshared (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* ___0_removeMethod, RuntimeObject* ___1_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B V_1;
	memset((&V_1), 0, sizeof(V_1));
	TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C* V_2 = NULL;
	ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* V_3 = NULL;
	ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* V_4 = NULL;
	bool V_5 = false;
	EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* V_6 = NULL;
	RuntimeObject* V_7 = NULL;
	{
		Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_0 = ___0_removeMethod;
		il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
		RuntimeObject* L_1;
		L_1 = NativeOrStaticEventRegistrationImpl_GetInstanceKey_m36F73D84E7D3A302C2C8E3ACECB7E49866CF4C1C(L_0, NULL);
		V_0 = L_1;
		MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* L_2 = ((NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_StaticFields*)il2cpp_codegen_static_fields_for(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var))->___s_eventCacheRWLock;
		il2cpp_codegen_memory_barrier();
		NullCheck(L_2);
		MyReaderWriterLock_AcquireReaderLock_m96E5ECF7E8F7635E7518D8882FE7FA304EC9309D(L_2, (-1), NULL);
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_006a:
			{
				il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
				MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* L_3 = ((NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_StaticFields*)il2cpp_codegen_static_fields_for(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var))->___s_eventCacheRWLock;
				il2cpp_codegen_memory_barrier();
				NullCheck(L_3);
				MyReaderWriterLock_ReleaseReaderLock_m00DB66CED452771CBBFED2BCD55730C9767F2ADE(L_3, NULL);
				return;
			}
		});
		try
		{
			{
				RuntimeObject* L_4 = V_0;
				Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_5 = ___0_removeMethod;
				il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_6;
				L_6 = NativeOrStaticEventRegistrationImpl_GetEventRegistrationTokenTableNoCreate_m580A1FCAB05541DBBE8CDD6574621D8F9D8EBF9C(L_4, L_5, (&V_2), NULL);
				V_3 = L_6;
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_7 = V_3;
				if (L_7)
				{
					goto IL_0023_1;
				}
			}
			{
				goto IL_007e;
			}

IL_0023_1:
			{
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_8 = V_3;
				V_4 = L_8;
				V_5 = (bool)0;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_005e_1:
					{
						{
							bool L_9 = V_5;
							if (!L_9)
							{
								goto IL_0069_1;
							}
						}
						{
							ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_10 = V_4;
							Monitor_Exit_m05B2CF037E2214B3208198C282490A2A475653FA((RuntimeObject*)L_10, NULL);
						}

IL_0069_1:
						{
							return;
						}
					}
				});
				try
				{
					{
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_11 = V_4;
						Monitor_Enter_m3CDB589DA1300B513D55FDCFB52B63E879794149((RuntimeObject*)L_11, (&V_5), NULL);
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_12 = V_3;
						RuntimeObject* L_13 = ___1_handler;
						NullCheck(L_12);
						RuntimeObject* L_14;
						L_14 = ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E(L_12, L_13, (&V_6), ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E_RuntimeMethod_var);
						V_7 = L_14;
						EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* L_15 = V_6;
						if (L_15)
						{
							goto IL_0048_2;
						}
					}
					{
						goto IL_007e;
					}

IL_0048_2:
					{
						EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* L_16 = V_6;
						NullCheck(L_16);
						bool L_17;
						L_17 = EventRegistrationTokenListWithCount_Pop_mD9C29E40F98D1A20AAF83702169F1A0CB11E750D(L_16, (&V_1), NULL);
						if (L_17)
						{
							goto IL_005c_2;
						}
					}
					{
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_18 = V_3;
						RuntimeObject* L_19 = V_7;
						NullCheck(L_18);
						bool L_20;
						L_20 = ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698(L_18, L_19, ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698_RuntimeMethod_var);
					}

IL_005c_2:
					{
						goto IL_0077;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0077:
	{
		Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_21 = ___0_removeMethod;
		EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B L_22 = V_1;
		NullCheck(L_21);
		Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_inline(L_21, L_22, NULL);
	}

IL_007e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeOrStaticEventRegistrationImpl_RemoveEventHandler_TisIl2CppFullySharedGenericAny_mBEE400B63122BBEB78402638E6160A7B99C16E30_gshared (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* ___0_removeMethod, Il2CppFullySharedGenericAny ___1_handler, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t828DF2F7F0859BA7B597AFF0C7C922A8624DA18C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T_t828DF2F7F0859BA7B597AFF0C7C922A8624DA18C);
	RuntimeObject* V_0 = NULL;
	EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B V_1;
	memset((&V_1), 0, sizeof(V_1));
	TokenListCount_t52D9E220227BAA2D3E0243CC23EFE1E54ECE5E0C* V_2 = NULL;
	ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* V_3 = NULL;
	ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* V_4 = NULL;
	bool V_5 = false;
	EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* V_6 = NULL;
	RuntimeObject* V_7 = NULL;
	{
		Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_0 = ___0_removeMethod;
		il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
		RuntimeObject* L_1;
		L_1 = NativeOrStaticEventRegistrationImpl_GetInstanceKey_m36F73D84E7D3A302C2C8E3ACECB7E49866CF4C1C(L_0, NULL);
		V_0 = L_1;
		MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* L_2 = ((NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_StaticFields*)il2cpp_codegen_static_fields_for(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var))->___s_eventCacheRWLock;
		il2cpp_codegen_memory_barrier();
		NullCheck(L_2);
		MyReaderWriterLock_AcquireReaderLock_m96E5ECF7E8F7635E7518D8882FE7FA304EC9309D(L_2, (-1), NULL);
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_006a:
			{
				il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
				MyReaderWriterLock_t228D12A218942E675CF1B49D299F795BC96E3970* L_3 = ((NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_StaticFields*)il2cpp_codegen_static_fields_for(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var))->___s_eventCacheRWLock;
				il2cpp_codegen_memory_barrier();
				NullCheck(L_3);
				MyReaderWriterLock_ReleaseReaderLock_m00DB66CED452771CBBFED2BCD55730C9767F2ADE(L_3, NULL);
				return;
			}
		});
		try
		{
			{
				RuntimeObject* L_4 = V_0;
				Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_5 = ___0_removeMethod;
				il2cpp_codegen_runtime_class_init_inline(NativeOrStaticEventRegistrationImpl_tAC9E5B36D0580765E176634E51A3F62346B05B90_il2cpp_TypeInfo_var);
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_6;
				L_6 = NativeOrStaticEventRegistrationImpl_GetEventRegistrationTokenTableNoCreate_m580A1FCAB05541DBBE8CDD6574621D8F9D8EBF9C(L_4, L_5, (&V_2), NULL);
				V_3 = L_6;
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_7 = V_3;
				if (L_7)
				{
					goto IL_0023_1;
				}
			}
			{
				goto IL_007e;
			}

IL_0023_1:
			{
				ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_8 = V_3;
				V_4 = L_8;
				V_5 = (bool)0;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_005e_1:
					{
						{
							bool L_9 = V_5;
							if (!L_9)
							{
								goto IL_0069_1;
							}
						}
						{
							ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_10 = V_4;
							Monitor_Exit_m05B2CF037E2214B3208198C282490A2A475653FA((RuntimeObject*)L_10, NULL);
						}

IL_0069_1:
						{
							return;
						}
					}
				});
				try
				{
					{
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_11 = V_4;
						Monitor_Enter_m3CDB589DA1300B513D55FDCFB52B63E879794149((RuntimeObject*)L_11, (&V_5), NULL);
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_12 = V_3;
						il2cpp_codegen_memcpy(L_13, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 0)) ? ___1_handler : &___1_handler), SizeOf_T_t828DF2F7F0859BA7B597AFF0C7C922A8624DA18C);
						RuntimeObject* L_14 = Box(il2cpp_rgctx_data_no_init(method->rgctx_data, 0), L_13);
						NullCheck(L_12);
						RuntimeObject* L_15;
						L_15 = ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E(L_12, L_14, (&V_6), ConditionalWeakTable_2_FindEquivalentKeyUnsafe_mCBF93A06F5ECA55FFB77D2EA2144B46C64709E1E_RuntimeMethod_var);
						V_7 = L_15;
						EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* L_16 = V_6;
						if (L_16)
						{
							goto IL_0048_2;
						}
					}
					{
						goto IL_007e;
					}

IL_0048_2:
					{
						EventRegistrationTokenListWithCount_t08BA4BD2F271ACE6EEEE0727790F88EBCE54A303* L_17 = V_6;
						NullCheck(L_17);
						bool L_18;
						L_18 = EventRegistrationTokenListWithCount_Pop_mD9C29E40F98D1A20AAF83702169F1A0CB11E750D(L_17, (&V_1), NULL);
						if (L_18)
						{
							goto IL_005c_2;
						}
					}
					{
						ConditionalWeakTable_2_t41A74963A0EDC80AE123649159914342B542862F* L_19 = V_3;
						RuntimeObject* L_20 = V_7;
						NullCheck(L_19);
						bool L_21;
						L_21 = ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698(L_19, L_20, ConditionalWeakTable_2_Remove_m6346F74865E02C6D37564EF494852AA66E953698_RuntimeMethod_var);
					}

IL_005c_2:
					{
						goto IL_0077;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0077:
	{
		Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* L_22 = ___0_removeMethod;
		EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B L_23 = V_1;
		NullCheck(L_22);
		Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_inline(L_22, L_23, NULL);
	}

IL_007e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBD6B0D9436820A5A075E4DEDAC5F272776C647AD_gshared (float* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int32_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	float* V_3 = NULL;
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		V_1 = 0;
		goto IL_0058;
	}

IL_000c:
	{
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		int32_t L_3 = ___3_scale;
		V_2 = ((int64_t)il2cpp_codegen_multiply(((int64_t)L_2), ((int64_t)L_3)));
		void* L_4 = ___1_base_addr;
		int64_t L_5 = V_2;
		V_3 = (float*)((void*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)L_5)));
		int32_t* L_6 = ___5_mask;
		if ((((intptr_t)L_6) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_003e;
		}
	}
	{
		int32_t* L_7 = ___5_mask;
		int32_t L_8 = V_1;
		uint32_t L_9 = sizeof(int32_t);
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))), L_10, il2cpp_rgctx_method(method->rgctx_data, 3));
		if ((((int32_t)L_11) >= ((int32_t)0)))
		{
			goto IL_0054;
		}
	}

IL_003e:
	{
		float* L_12 = ___0_dptr;
		int32_t L_13 = V_1;
		uint32_t L_14 = sizeof(float);
		float* L_15 = V_3;
		float L_16 = (*(float*)L_15);
		*(float*)((float*)il2cpp_codegen_add((intptr_t)L_12, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_13), (int32_t)L_14)))) = L_16;
	}

IL_0054:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0058:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = ___4_n;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_000c;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_m78BBC4DBE234DA027814A059C7A569C168B14265_gshared (Il2CppFullySharedGenericStruct* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, Il2CppFullySharedGenericStruct* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	void* L_11 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	const uint32_t SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_17 = alloca(SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
	const Il2CppFullySharedGenericStruct L_10 = alloca(SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	memset(V_0, 0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	Il2CppFullySharedGenericStruct* V_3 = NULL;
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
		V_1 = 0;
		goto IL_0058;
	}

IL_000c:
	{
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		int32_t L_3 = ___3_scale;
		V_2 = ((int64_t)il2cpp_codegen_multiply(((int64_t)L_2), ((int64_t)L_3)));
		void* L_4 = ___1_base_addr;
		int64_t L_5 = V_2;
		V_3 = (Il2CppFullySharedGenericStruct*)((void*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)L_5)));
		Il2CppFullySharedGenericStruct* L_6 = ___5_mask;
		if ((((intptr_t)L_6) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_003e;
		}
	}
	{
		Il2CppFullySharedGenericStruct* L_7 = ___5_mask;
		int32_t L_8 = V_1;
		uint32_t L_9 = SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594;
		il2cpp_codegen_memcpy(L_10, V_0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
		int32_t L_12;
		L_12 = ConstrainedFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 3), L_11, (void*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))), L_10);
		if ((((int32_t)L_12) >= ((int32_t)0)))
		{
			goto IL_0054;
		}
	}

IL_003e:
	{
		Il2CppFullySharedGenericStruct* L_13 = ___0_dptr;
		int32_t L_14 = V_1;
		uint32_t L_15 = SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314;
		Il2CppFullySharedGenericStruct* L_16 = V_3;
		il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_14), (int32_t)L_15)))), L_17, SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 5), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_14), (int32_t)L_15)))), (void*)L_17);
	}

IL_0054:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}

IL_0058:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = ___4_n;
		if ((((int32_t)L_19) < ((int32_t)L_20)))
		{
			goto IL_000c;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72_gshared (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276_gshared (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A_gshared (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0_gshared (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uint8_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (uint8_t*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE_gshared (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		int32_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (int32_t*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F_gshared (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		intptr_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (intptr_t*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81_gshared (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uint64_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (uint64_t*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F_gshared (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726_gshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784_gshared (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4_gshared (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21_gshared (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Resize_TisIl2CppFullySharedGenericStruct_m07039200651D43DBB7FBC0CB244761DA34C164FD_gshared (Il2CppFullySharedGenericStruct* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (Il2CppFullySharedGenericStruct*)(L_6);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)(L_6);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m45D0A38692AC9D6D49A127721F451779033C800F_gshared_inline (Action_1_t2F6697C5DA7073FCAE212D3900E184AF5BA9E722* __this, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B ___0_obj, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, EventRegistrationToken_tFEB6E75BA7C6603DB3207E3ABA9156228EB87F1B, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint8_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(intptr_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint64_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		return (int32_t)L_0;
	}
}
