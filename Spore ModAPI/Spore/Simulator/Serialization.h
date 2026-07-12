#pragma once

#include <EASTL\map.h>
#include <Spore\App\Property.h>
#include <Spore\Resource\IRecord.h>
#include <Spore\Resource\Database.h>
#include <Spore\Object.h>
#include <Spore\Simulator\ISimulatorSerializable.h>

#define ISerializerDatabasePtr eastl::intrusive_ptr<Simulator::ISerializerDatabase>
#define ISerializerReadStreamPtr eastl::intrusive_ptr<Simulator::ISerializerReadStream>
#define ISerializerWriteStreamPtr eastl::intrusive_ptr<Simulator::ISerializerWriteStream>
#define ICOMSerializerPtr eastl::intrusive_ptr<Simulator::ICOMSerializer>

#define SerializerDatabasePtr eastl::intrusive_ptr<Simulator::SerializerDatabase>
#define SerializerReadStreamPtr eastl::intrusive_ptr<Simulator::SerializerReadStream>
#define SerializerWriteStreamPtr eastl::intrusive_ptr<Simulator::SerializerWriteStream>
#define COMSerializerPtr eastl::intrusive_ptr<Simulator::COMSerializer>

namespace Simulator
{
	class ICOMSerializer;
	class ISerializerReadStream;
	class ISerializerWriteStream;

	class ISerializerDatabase
		: public Object
	{
	public:
		static const uint32_t TYPE = 0x19DA51A;

		/* 10h */	virtual Resource::Database* AsDatabase() = 0;
		/* 14h */	virtual ICOMSerializer* GetCOMSerializer() = 0;
		/* 18h */	virtual bool OpenReadStream(const ResourceKey& key, ISerializerReadStream** ppStream) = 0;
		/* 1Ch */	virtual bool CloseReadStream(ISerializerReadStream* pStream) = 0;
		/* 20h */	virtual bool LoadClassObjects(uint32_t version) = 0;
		/* 24h */	virtual bool OpenWriteStream(const ResourceKey& key, ISerializerWriteStream** ppStream, bool bTruncate) = 0;
		/* 28h */	virtual bool CloseWriteStream(ISerializerWriteStream* pStream) = 0;
		/* 2Ch */	virtual bool SaveClassObjects() = 0;
		/* 30h */	virtual bool HasKey(const ResourceKey& key) const = 0;
		/* 34h */	virtual float GetPercentageCompletion() const = 0;
		/* 38h */	virtual void SetPercentageCompletion(float fPercentageCompletion0To100) = 0;
	};

	class ISerializerStream
		: public Object
	{
	};

	class ISerializerReadStream 
		: public ISerializerStream
	{
	public:
		static const uint32_t TYPE = 0x179CD60;

		/* 10h */	virtual bool Open(ISerializerDatabase* pDatabase, const ResourceKey& key) = 0;
		/* 14h */	virtual bool Close() = 0;
		/* 18h */	virtual bool IsOpen() const = 0;
		/* 1Ch */	virtual bool IsGood() const = 0;
		/* 20h */	virtual Resource::IRecord* GetRecord() const = 0;
		/* 24h */	virtual ISerializerDatabase* GetDatabase() const = 0;
		/* 28h */	virtual bool ReadObjectPointer(uint32_t castTypeID, ObjectPtr& dst, bool bLoadImmediately) = 0;
		/* 2Ch */	virtual bool ReadPointer(ISimulatorSerializable* pointer, bool bLoadImmediately) = 0;
		/* 30h */	virtual bool ReadProperty(App::Property& dst) = 0;
		/* 34h */	virtual bool ReadRawData(void* pBuffer, size_t size) = 0;
	protected:
		// Deprecated.
		/* 38h */	virtual bool ReadPropertyByID(uint32_t propertyID, App::Property& dst) = 0;
	public:
		/* 3Ch */	virtual uint32_t GetSerializationVersion() const = 0;
		/* 40h */	virtual void SetSerializationVersion(uint32_t version) = 0;
	};

	class ISerializerWriteStream
		: public ISerializerStream
	{
	public:
		static const uint32_t TYPE = 0x179CD61;

		/* 10h */	virtual bool Open(ISerializerDatabase* pDatabase, const ResourceKey& key, bool bTruncate) = 0;
		/* 14h */	virtual bool Close() = 0;
		/* 18h */	virtual bool IsOpen() const = 0;
		/* 1Ch */	virtual bool IsGood() const = 0;
		/* 20h */	virtual Resource::IRecord* GetRecord() const = 0;
		/* 24h */	virtual ISerializerDatabase* GetDatabase() const = 0;
		/* 28h */	virtual bool WriteObjectPointer(Object* pObject) = 0;
		/* 2Ch */	virtual bool WritePointer(ISimulatorSerializable* pointer) = 0;
		/* 30h */	virtual bool WriteProperty(App::Property& src) = 0;
		/* 34h */	virtual bool WriteRawData(void* pData, size_t size) = 0;
	protected:
		// Deprecated.
		/* 38h */	virtual bool WritePropertyWithID(uint32_t propertyID, App::Property& src) = 0;
	};

	class ICOMSerializer
		: public Object
	{
	public:
		static const uint32_t TYPE = 0x179D2A7;

		enum DataIDs
		{
			kRecordGroupID_Default = 0x179D304,
			kRecordInstanceID_Default = 0x0,
			kRecordTypeID_Classes = 0x179D310
		};

		/* 10h */	virtual bool Open(ISerializerDatabase* pDatabase, int mode_DEPRECATED) = 0;
		/* 14h */	virtual bool Close() = 0;
		/* 18h */	virtual bool LoadClassObjects(uint32_t clientVersion) = 0;
		/* 1Ch */	virtual bool SaveClassObjects() = 0;
		/* 20h */	virtual bool Write(ISerializerWriteStream& oSPStream, const ISimulatorSerializable* pSerializable) = 0;
		/* 24h */	virtual bool Read(ISerializerReadStream& iSPStream, const ISimulatorSerializable** ppSerializable, bool bLoadImmediately) = 0;
	};

	//class SerializerStream
	//	: public DefaultRefCounted
	//	, public ISerializerStream
	//{
	//protected:
	//	/* 0Ch */	bool field_0C;
	//	/* 10h */	int field_10;
	//	/* 14h */	Resource::IRecord* mpRecord;
	//	/* 18h */	int field_18;
	//};

	struct Attribute;

	/// The type of function used to read binary attribute data. 
	/// The parameters are the data serializer and the address of memory where the data must be read.
	typedef bool(*ReadFunction_t)(ISerializerReadStream*, void*);
	/// The type of function used to write binary attribute data. 
	/// The parameters are the data serializer and the address of memory where the data is.
	typedef bool(*WriteFunction_t)(ISerializerWriteStream*, void*);

	/// The type of function used to read attribute data, which is expressed in text. 
	/// The parameters are the text eastl::string and the address of memory where the data must be read.
	typedef void(*ReadTextFunction_t)(const eastl::string&, void*);
	/// The type of function used to write attribute data, which is expressed in text. 
	/// The parameters are the destination text buffer and the address of memory where the data is.
	typedef void(*WriteTextFunction_t)(char*, void*);

	typedef bool(*UnknownFunction_t)();
	typedef bool(*UnknownFunction2_t)(void*, const char*, int);
	typedef void*(*OffsetFunction_t)(Attribute*);

	struct Attribute
	{
		static bool DefaultUnknownFunction() { return true; }
		static bool DefaultUnknownFunction2(void*, const char*, int) { return true; }
		static void* DefaultOffset(Attribute*);

		Attribute() = default;
		Attribute(const char*, uint32_t, size_t,
			ReadFunction_t, WriteFunction_t, ReadTextFunction_t, WriteTextFunction_t, UnknownFunction2_t);

		/* 00h */	const char* name;
		/* 04h */	uint32_t id;
		/* 08h */	size_t offset;
		/* 0Ch */	int field_0C;  // not initialized
		/* 10h */	int field_10;  // not initialized
		/* 14h */	int field_14;  // not initialized
		/* 18h */	void* pCurrentObject;
		/* 1Ch */	int field_1C;
		/* 20h */	OffsetFunction_t offsetFunction;
		/* 24h */	ReadFunction_t readFunction;
		/* 28h */	WriteFunction_t writeFunction;
		/* 2Ch */	ReadTextFunction_t readTextFunction;
		/* 30h */	WriteTextFunction_t writeTextFunction;
		/* 34h */	UnknownFunction_t field_34;
		/* 38h */	UnknownFunction2_t field_38;
	};
	ASSERT_SIZE(Attribute, 0x3C);

	struct ClassSerializer
	{
		struct AttributePointer
		{
			/* 00h */	uint32_t id;
			/* 04h */	uint32_t dataSize;
			/* 08h */	bool serialized;
			/* 0Ch */	void* pBinderContext;   // field_18 of the attribute
			/* 10h */	Attribute* pAttribute;
		};

		static const uint32_t CLASS_ID = 0x1A80D26;

		ClassSerializer(void* pObject, Attribute* attributes, uint32_t classID = 0x1A80D26);

		// Attributes are searched with a binary search, they must be ordered
		AttributePointer attributes[128];
		/* A00h */	int count;
		/* A04h */	int countSerialized;  // count of attributes written
		/* A08h */	uint32_t id;
		/* A0Ch */	void* pObject;
		/* A10h */	Attribute* pAttributes;

		bool Read(ISerializerStream* pStream);
		bool Write(ISerializerStream* pStream);
	};
	ASSERT_SIZE(ClassSerializer, 0xA14);

	namespace Addresses(ClassSerializer) 
	{
		DeclareAddress(Read);
		DeclareAddress(Write);
	}

	class XmlSerializer
	{
		// it has things, but we are not really interested
	public:
		bool AttributesToXml(Attribute* attributes, void* object, const char* name);
	};

	namespace Addresses(XmlSerializer)
	{
		DeclareAddress(AttributesToXml);
	}

	class COMSerializer
		: public DefaultRefCounted
		, public ICOMSerializer
	{
	public:
		COMSerializer(ISerializerDatabase* pDatabase);

		virtual int AddRef() override;
		virtual int Release() override;
		virtual void* Cast(uint32_t type) const override;

		virtual bool Open(ISerializerDatabase* pDatabase, int mode_DEPRECATED) override;
		virtual bool Close() override;
		virtual bool LoadClassObjects(uint32_t clientVersion) override;
		virtual bool SaveClassObjects() override;
		virtual bool Write(ISerializerWriteStream& oSPStream, const ISimulatorSerializable* pSerializable) override;
		virtual bool Read(ISerializerReadStream& iSPStream, const ISimulatorSerializable** ppSerializable, bool bLoadImmediately) override;
	protected:
		bool GetCRC(Resource::IRecord* pRecord, uint32_t nCRCDataLength, uint32_t& nCRC);
		void reset();
		bool onSetSPSerializable(const ISimulatorSerializable* pSerializable, uint32_t instanceID, uint32_t classID);
		bool onGetSPSerializable(ISimulatorSerializable** ppSerializable, uint32_t instanceID, uint32_t classID);
		bool loadSingleObject(ISimulatorSerializable* pSerializable, uint32_t instanceID, uint32_t classID);

		struct IDInfo
		{
			/* 00h */	eastl::intrusive_ptr<ISimulatorSerializable> mpSerializable;
		};
		ASSERT_SIZE(IDInfo, 0x4);

		struct ClassInfo
		{
			/* 00h */	uint32_t mReadInstanceCount;
			/* 04h */	uint32_t mInstanceCount;
			/* 08h */	eastl::map<uint32_t, IDInfo, eastl::less<uint32_t>> mInstanceIDMap;
		};
		ASSERT_SIZE(ClassInfo, 0x24);

		/* 0Ch */	bool mbBusyWritingClassObjects;
		/* 10h */	eastl::map<uint32_t, ClassInfo, eastl::less<uint32_t>> mClassIDMapForWriting;
		/* 2Ch */	eastl::map<uint32_t, ClassInfo, eastl::less<uint32_t>> mClassIDMap;
		/* 48h */	int mTotalSerializableCount;
		/* 4Ñh */	bool mbClassObjectsLoaded;
		/* 4Dh */	bool mbClassObjectsSaved;
		/* 50h */	ISerializerDatabasePtr mpDatabase;
		/* 54h */	eastl::vector<uint8_t> mCRCDataBuffer;
	};
	ASSERT_SIZE(COMSerializer, 0x68);

	namespace Addresses(COMSerializer)
	{
		DeclareAddress(Open);
		DeclareAddress(Close);
		DeclareAddress(LoadClassObjects);
		DeclareAddress(SaveClassObjects);
		DeclareAddress(Write);
		DeclareAddress(Read);
		DeclareAddress(GetCRC);
		DeclareAddress(reset);
		DeclareAddress(onSetSPSerializable);
		DeclareAddress(onGetSPSerializable);
		DeclareAddress(loadSingleObject);
	}

	class SerializerDatabase
		: public ISerializerDatabase
		, public Resource::Database
		, public DefaultRefCounted
	{
	public:
		SerializerDatabase(Resource::Database* pDatabase);

		virtual int AddRef() override;
		virtual int Release() override;
		virtual void* Cast(uint32_t type) const override;

		virtual Resource::Database* AsDatabase() override;
		virtual ICOMSerializer* GetCOMSerializer() override;
		virtual bool OpenReadStream(const ResourceKey& key, ISerializerReadStream** ppStream) override;
		virtual bool CloseReadStream(ISerializerReadStream* pStream) override;
		virtual bool LoadClassObjects(uint32_t version) override;
		virtual bool OpenWriteStream(const ResourceKey& key, ISerializerWriteStream** ppStream, bool bTruncate) override;
		virtual bool CloseWriteStream(ISerializerWriteStream* pStream) override;
		virtual bool SaveClassObjects() override;
		virtual bool HasKey(const ResourceKey& key) const override;
		virtual float GetPercentageCompletion() const override;
		virtual void SetPercentageCompletion(float fPercentageCompletion0To100) override;

		virtual bool Initialize() override;
		virtual bool Dispose() override;
		virtual uint32_t GetDatabaseType() const override;
		virtual int GetRefCount() const override;
		virtual void Lock(bool lock) override;
		virtual bool Open(IO::AccessFlags desiredAccess = IO::AccessFlags::Read, IO::CD createDisposition = IO::CD::Default, bool bAutoOpen = false) override;
		virtual bool Close() override;
		virtual IO::AccessFlags GetAccessFlags() const override;
		virtual bool Flush() override;
		virtual const char16_t* GetLocation() const override;
		virtual bool SetLocation(const char16_t* path) override;
		virtual size_t GetKeyList(eastl::vector<ResourceKey>& dstVector, Resource::IKeyFilter* filter = nullptr) override;
		virtual bool OpenRecord(
			const ResourceKey& name,
			Resource::IRecord** ppDst,
			IO::AccessFlags desiredAccess = IO::AccessFlags::Read,
			IO::CD createDisposition = IO::CD::Default,
			bool arg_10 = true,
			Resource::RecordInfo* pDstInfo = nullptr) override;
		virtual int GetOpenCount(const ResourceKey& key) override;
		virtual bool CloseRecord(Resource::IRecord* pRecord) override;
		virtual bool DeleteRecord(const ResourceKey& name) override;
		virtual bool Attach(bool, Resource::IResourceManager* pResourceMan, bool) override;
		virtual ICoreAllocator* GetAllocator() const override;

		virtual bool OpenAsSerializer(bool bOpenForReading, bool bOpenForWriting);
	protected:
		/* 18h */	eastl::intrusive_ptr<Resource::Database> mpDatabase;
		/* 1Ch */	eastl::intrusive_ptr<ICOMSerializer> mpCOMSerializer;
		/* 20h */	float mfPercentageCompletion0To100;
	};
	ASSERT_SIZE(SerializerDatabase, 0x24);

	namespace Addresses(SerializerDatabase)
	{
		DeclareAddress(AsDatabase);
		DeclareAddress(GetCOMSerializer);
		DeclareAddress(OpenReadStream);
		DeclareAddress(CloseReadStream);
		DeclareAddress(LoadClassObjects);
		DeclareAddress(OpenWriteStream);
		DeclareAddress(CloseWriteStream);
		DeclareAddress(SaveClassObjects);
		DeclareAddress(HasKey);
		DeclareAddress(GetPercentageCompletion);
		DeclareAddress(SetPercentageCompletion);
		DeclareAddress(Initialize);
		DeclareAddress(Dispose);
		DeclareAddress(GetDatabaseType);
		DeclareAddress(GetRefCount);
		DeclareAddress(Lock);
		DeclareAddress(Open);
		DeclareAddress(Close);
		DeclareAddress(GetAccessFlags);
		DeclareAddress(Flush);
		DeclareAddress(GetLocation);
		DeclareAddress(SetLocation);
		DeclareAddress(GetKeyList);
		DeclareAddress(OpenRecord);
		DeclareAddress(GetOpenCount);
		DeclareAddress(CloseRecord);
		DeclareAddress(DeleteRecord);
		DeclareAddress(Attach);
		DeclareAddress(GetAllocator);
		DeclareAddress(OpenAsSerializer);
	}

	class SerializerReadStream
		: DefaultRefCounted
		, ISerializerReadStream
	{
	public:
		SerializerReadStream();

		virtual void* Cast(uint32_t type) const override;

		virtual bool Open(ISerializerDatabase* pDatabase, const ResourceKey& key) override;
		virtual bool Close() override;
		virtual bool IsOpen() const override;
		virtual bool IsGood() const override;
		virtual Resource::IRecord* GetRecord() const override;
		virtual ISerializerDatabase* GetDatabase() const override;
		virtual bool ReadObjectPointer(uint32_t castTypeID, ObjectPtr& dst, bool bLoadImmediately) override;
		virtual bool ReadPointer(ISimulatorSerializable* pointer, bool bLoadImmediately) override;
		virtual bool ReadProperty(App::Property& dst) override;
		virtual bool ReadRawData(void* pBuffer, size_t size) override;
	protected:
		// Deprecated.
		virtual bool ReadPropertyByID(uint32_t propertyID, App::Property& dst) override;
	public:
		virtual uint32_t GetSerializationVersion() const override;
		virtual void SetSerializationVersion(uint32_t version) override;

		virtual bool Skip(const uint32_t skipCount);
	protected:
		/* 0Ch */	bool mbOK;
		/* 10h */	uint32_t mVersion;
		/* 14h */	eastl::intrusive_ptr<Resource::IRecord> mpRecord;
		/* 18h */	eastl::intrusive_ptr<ISerializerDatabase> mpDatabase;
	};
	ASSERT_SIZE(SerializerReadStream, 0x1C);

	namespace Addresses(SerializerReadStream)
	{
		DeclareAddress(Open);
		DeclareAddress(Close);
		DeclareAddress(IsOpen);
		DeclareAddress(IsGood);
		DeclareAddress(GetRecord);
		DeclareAddress(GetDatabase);
		DeclareAddress(ReadObjectPointer);
		DeclareAddress(ReadPointer);
		DeclareAddress(ReadProperty);
		DeclareAddress(ReadRawData);
		DeclareAddress(ReadPropertyByID);
		DeclareAddress(GetSerializationVersion);
		DeclareAddress(SetSerializationVersion);
		DeclareAddress(Skip);
	}

	class SerializerWriteStream
		: DefaultRefCounted
		, ISerializerWriteStream
	{
	public:
		SerializerWriteStream();

		virtual void* Cast(uint32_t type) const override;

		virtual bool Open(ISerializerDatabase* pDatabase, const ResourceKey& key, bool bTruncate) override;
		virtual bool Close() override;
		virtual bool IsOpen() const override;
		virtual bool IsGood() const override;
		virtual Resource::IRecord* GetRecord() const override;
		virtual ISerializerDatabase* GetDatabase() const override;
		virtual bool WriteObjectPointer(Object* pObject) override;
		virtual bool WritePointer(ISimulatorSerializable* pointer) override;
		virtual bool WriteProperty(App::Property& src) override;
		virtual bool WriteRawData(void* pData, size_t size) override;
	protected:
		// Deprecated.
		virtual bool WritePropertyWithID(uint32_t propertyID, App::Property& src) override;

		/* 0Ch */	eastl::intrusive_ptr<Resource::IRecord> mpRecord;
		/* 10h */	eastl::intrusive_ptr<ISerializerDatabase> mpDatabase;
		/* 14h */	bool mbOK;
	};
	ASSERT_SIZE(SerializerWriteStream, 0x18);

	namespace Addresses(SerializerWriteStream)
	{
		DeclareAddress(Open);
		DeclareAddress(Close);
		DeclareAddress(IsOpen);
		DeclareAddress(IsGood);
		DeclareAddress(GetRecord);
		DeclareAddress(GetDatabase);
		DeclareAddress(WriteObjectPointer);
		DeclareAddress(WritePointer);
		DeclareAddress(WriteProperty);
		DeclareAddress(WriteRawData);
		DeclareAddress(WritePropertyWithID);
	}

	class SerializerReadStreamPrivate
	{
	public:
		SerializerReadStreamPrivate(ISerializerReadStream& readStream, const ResourceKey& key);
		SerializerReadStreamPrivate(ISerializerDatabase* pDatabase, const ResourceKey& key);
		SerializerReadStreamPrivate(ISerializerReadStream& readStream, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);
		SerializerReadStreamPrivate(ISerializerDatabase* pDatabase, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);

		virtual ~SerializerReadStreamPrivate();

		bool IsOpen();
		void SetSerializationVersion(uint32_t version);
		uint32_t GetSerializationVersion() const;

		/* 04h */	eastl::intrusive_ptr<ISerializerDatabase> mpDatabase;
		/* 08h */	eastl::intrusive_ptr<ISerializerReadStream> mpReadStream;
	protected:
		bool openStream(ISerializerDatabase* pDatabase, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);
	};
	ASSERT_SIZE(SerializerReadStreamPrivate, 0xC);

	namespace Addresses(SerializerReadStreamPrivate)
	{
		DeclareAddress(IsOpen);
		DeclareAddress(SetSerializationVersion);
		DeclareAddress(GetSerializationVersion);
		DeclareAddress(openStream);
	}

	class SerializerWriteStreamPrivate
	{
	public:
		SerializerWriteStreamPrivate(ISerializerWriteStream& writeStream, const ResourceKey& key);
		SerializerWriteStreamPrivate(ISerializerDatabase* pDatabase, const ResourceKey& key);
		SerializerWriteStreamPrivate(ISerializerWriteStream& writeStream, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);
		SerializerWriteStreamPrivate(ISerializerDatabase* pDatabase, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);

		virtual ~SerializerWriteStreamPrivate();

		bool IsOpen();

		/* 04h */	eastl::intrusive_ptr<ISerializerDatabase> mpDatabase;
		/* 08h */	eastl::intrusive_ptr<ISerializerWriteStream> mpWriteStream;
	protected:
		bool openStream(ISerializerDatabase* pDatabase, uint32_t nResourceType, uint32_t nInstance, uint32_t nGroupID);
	};
	ASSERT_SIZE(SerializerWriteStreamPrivate, 0xC);

	namespace Addresses(SerializerWriteStreamPrivate)
	{
		DeclareAddress(IsOpen);
		DeclareAddress(openStream);
	}
}

