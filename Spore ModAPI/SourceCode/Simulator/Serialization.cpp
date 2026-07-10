#include <Spore\Simulator\Serialization.h>

namespace Simulator
{
	ClassSerializer::ClassSerializer(void* _pObject, Attribute _attributes[], uint32_t classID)
		: pObject(_pObject)
		, pAttributes(_attributes)
		, id(classID)
		, count(0)
		, countSerialized(0)
	{
		Attribute* ptr = _attributes;
		while (ptr->readFunction && ptr->writeFunction && count < 128) {
			attributes[count++] = {ptr->id, 0, false, ptr->pCurrentObject, ptr};
			ptr += 1;
		}
	}

	auto_METHOD(ClassSerializer, bool, Read, Args(ISerializerStream* pStream), Args(pStream));
	auto_METHOD(ClassSerializer, bool, Write, Args(ISerializerStream* pStream), Args(pStream));

	auto_METHOD(XmlSerializer, bool, AttributesToXml,
		Args(Attribute* attributes, void* object, const char* name), Args(attributes, object, name));

	void* Attribute::DefaultOffset(Attribute* ptr) {
		return (char*)ptr->pCurrentObject + ptr->offset;
	}

	Attribute::Attribute(const char* _name, uint32_t _id, size_t _offset,
		ReadFunction_t read, WriteFunction_t write, ReadTextFunction_t readText, WriteTextFunction_t writeText, 
		UnknownFunction2_t _field_38)
		: name(_name)
		, id(_id)
		, offset(_offset)
		, readFunction(read)
		, writeFunction(write)
		, readTextFunction(readText)
		, writeTextFunction(writeText)
		, field_38(_field_38)
		, field_34(&Attribute::DefaultUnknownFunction)
		, offsetFunction(&Attribute::DefaultOffset)
		, pCurrentObject(nullptr)
		, field_1C(0)
	{

	}

#ifndef MODAPI_DLL_EXPORT

	ICOMSerializer::~ICOMSerializer() = default;

	COMSerializer::COMSerializer(ISerializerDatabase* pDatabase)
		: mbBusyWritingClassObjects(false)
		, mClassIDMapForWriting()
		, mClassIDMap()
		, mTotalSerializableCount(0)
		, mbClassObjectsLoaded(false)
		, mbClassObjectsSaved(false)
		, mpDatabase(nullptr)
		, mCRCDataBuffer()
	{
		reset();
		mpDatabase = pDatabase;
	}

	COMSerializer::~COMSerializer() = default;

	int COMSerializer::AddRef()
	{
		return DefaultRefCounted::AddRef();
	}

	int COMSerializer::Release()
	{
		return DefaultRefCounted::Release();
	}

	void* COMSerializer::Cast(uint32_t type) const
	{
		CLASS_CAST(ICOMSerializer);
		return nullptr;
	}

	auto_METHOD_VIRTUAL(COMSerializer, ICOMSerializer, bool, Open,
		Args(ISerializerDatabase* pDatabase),
		Args(pDatabase));
	auto_METHOD_VIRTUAL_(COMSerializer, ICOMSerializer, bool, Close);
	auto_METHOD_VIRTUAL(COMSerializer, ICOMSerializer, bool, LoadClassObjects,
		Args(uint32_t clientVersion),
		Args(clientVersion));
	auto_METHOD_VIRTUAL_(COMSerializer, ICOMSerializer, bool, SaveClassObjects);
	auto_METHOD_VIRTUAL(COMSerializer, ICOMSerializer, bool, Write,
		Args(ISerializerWriteStream& oSPStream, const ISimulatorSerializable* pSerializable),
		Args(oSPStream, pSerializable));
	auto_METHOD_VIRTUAL(COMSerializer, ICOMSerializer, bool, Read,
		Args(ISerializerReadStream& iSPStream, const ISimulatorSerializable** ppSerializable, bool bLoadImmediately),
		Args(iSPStream, ppSerializable, bLoadImmediately));

	auto_METHOD(COMSerializer, bool, GetCRC,
		Args(Resource::IRecord* pRecord, uint32_t nCRCDataLength, uint32_t& nCRC),
		Args(pRecord, nCRCDataLength, nCRC));
	auto_METHOD_VOID_(COMSerializer, reset);
	auto_METHOD(COMSerializer, bool, onSetSPSerializable,
		Args(const ISimulatorSerializable* pSerializable, uint32_t instanceID, uint32_t classID),
		Args(pSerializable, instanceID, classID));
	auto_METHOD(COMSerializer, bool, onGetSPSerializable,
		Args(ISimulatorSerializable** ppSerializable, uint32_t instanceID, uint32_t classID),
		Args(ppSerializable, instanceID, classID));
	auto_METHOD(COMSerializer, bool, loadSingleObject,
		Args(ISimulatorSerializable* pSerializable, uint32_t instanceID, uint32_t classID),
		Args(pSerializable, instanceID, classID));

	SerializerDatabase::SerializerDatabase(Database* pDatabase)
		: mpDatabase(pDatabase)
		, mpCOMSerializer(new COMSerializer(this))
		, mfPercentageCompletion0To100(0.0f)
	{

	}

	SerializerDatabase::~SerializerDatabase() = default;

	int SerializerDatabase::AddRef()
	{
		return Database::AddRef();
	}

	int SerializerDatabase::Release()
	{
		return Database::Release();
	}

	void* SerializerDatabase::Cast(uint32_t type) const
	{
		CLASS_CAST(ISerializerDatabase);
		return nullptr;
	}

	auto_METHOD_VIRTUAL_(SerializerDatabase, ISerializerDatabase, Resource::Database*, AsDatabase);
	auto_METHOD_VIRTUAL_(SerializerDatabase, ISerializerDatabase, ICOMSerializer*, GetCOMSerializer);
	auto_METHOD_VIRTUAL(SerializerDatabase, ISerializerDatabase, bool, OpenReadStream,
		Args(const ResourceKey& key, ISerializerReadStream** ppStream),
		Args(key, ppStream));
	auto_METHOD_VIRTUAL(SerializerDatabase, ISerializerDatabase, bool, CloseReadStream,
		Args(ISerializerReadStream* pStream),
		Args(pStream));
	auto_METHOD_VIRTUAL(SerializerDatabase, ISerializerDatabase, bool, LoadClassObjects,
		Args(uint32_t version),
		Args(version));
	auto_METHOD_VIRTUAL(SerializerDatabase, ISerializerDatabase, bool, OpenWriteStream,
		Args(const ResourceKey& key, ISerializerWriteStream** ppStream, bool bTruncate),
		Args(key, ppStream, bTruncate));
	auto_METHOD_VIRTUAL(SerializerDatabase, ISerializerDatabase, bool, CloseWriteStream,
		Args(ISerializerWriteStream* pStream),
		Args(pStream));
	auto_METHOD_VIRTUAL_(SerializerDatabase, ISerializerDatabase, bool, SaveClassObjects);
	auto_METHOD_VIRTUAL_const(SerializerDatabase, ISerializerDatabase, bool, HasKey,
		Args(const ResourceKey& key),
		Args(key));
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, ISerializerDatabase, float, GetPercentageCompletion);
	auto_METHOD_VIRTUAL_VOID(SerializerDatabase, ISerializerDatabase, SetPercentageCompletion,
		Args(float fPercentageCompletion0To100),
		Args(fPercentageCompletion0To100));

	auto_METHOD_VIRTUAL_(SerializerDatabase, Resource::Database, bool, Initialize);
	auto_METHOD_VIRTUAL_(SerializerDatabase, Resource::Database, bool, Dispose);
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, Resource::Database, uint32_t, GetDatabaseType);
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, Resource::Database, int, GetRefCount);
	auto_METHOD_VIRTUAL_VOID(SerializerDatabase, Resource::Database, Lock,
		Args(bool lock),
		Args(lock));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, Open,
		Args(IO::AccessFlags desiredAccess, IO::CD createDisposition, bool bAutoOpen),
		Args(desiredAccess, createDisposition, bAutoOpen));
	auto_METHOD_VIRTUAL_(SerializerDatabase, Resource::Database, bool, Close);
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, Resource::Database, IO::AccessFlags, GetAccessFlags);
	auto_METHOD_VIRTUAL_(SerializerDatabase, Resource::Database, bool, Flush);
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, Resource::Database, const char16_t*, GetLocation);
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, SetLocation,
		Args(const char16_t* path),
		Args(path));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, size_t, GetKeyList,
		Args(eastl::vector<ResourceKey>& dstVector, Resource::IKeyFilter* filter),
		Args(dstVector, filter));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, OpenRecord,
		Args(const ResourceKey& name, Resource::IRecord** ppDst, IO::AccessFlags desiredAccess, IO::CD createDisposition, bool arg_10, Resource::RecordInfo* pDstInfo),
		Args(name, ppDst, desiredAccess, createDisposition, arg_10, pDstInfo));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, int, GetOpenCount,
		Args(const ResourceKey& key),
		Args(key));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, CloseRecord,
		Args(Resource::IRecord* pRecord),
		Args(pRecord));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, DeleteRecord,
		Args(const ResourceKey& name),
		Args(name));
	auto_METHOD_VIRTUAL(SerializerDatabase, Resource::Database, bool, Attach,
		Args(bool arg_0, Resource::IResourceManager* pResourceMan, bool arg_8),
		Args(arg_0, pResourceMan, arg_8));
	auto_METHOD_VIRTUAL_const_(SerializerDatabase, Resource::Database, ICoreAllocator*, GetAllocator);

	auto_METHOD_VIRTUAL(SerializerDatabase, SerializerDatabase, bool, OpenAsSerializer,
		Args(bool bOpenForReading, bool bOpenForWriting),
		Args(bOpenForReading, bOpenForWriting));

#endif

}