#pragma once

#include <Spore\IO\IStream.h>

#define StreamCompressionZLibPtr eastl::intrusive_ptr<IO::StreamCompressionZLib>
#define StreamDecompressionZLibPtr eastl::intrusive_ptr<IO::StreamDecompressionZLib>

namespace IO
{
	enum CompressedFormat
	{
		kCompressedFormatZLib,
		kCompressedFormatGZip
	};

	class StreamCompressionZLib : public IStream, public RefCountTemplateAtomic
	{
	public:

		static const uint32_t TYPE = 0x23bdad7;

		enum CompressionHint
		{
			kCompressionHintNone = 0,
			kCompressionHintSpeed = 1,
			kCompressionHintSize = 9,
			kCompressionHintDefault = -1
		};

	public:
		StreamCompressionZLib(IStream* pOutputStream, int nHint);

		~StreamCompressionZLib();

		/* 04h */	virtual int AddRef() override;
		/* 08h */	virtual int Release() override;

		/* 0Ch */	virtual uint32_t GetType() const override;
		/* 10h */	virtual AccessFlags GetAccessFlags() const override;
		/* 14h */	virtual FileError GetState() const override;
		/* 18h */	virtual bool Close() override;

		/* 1Ch */	virtual size_type GetSize() const override;
		/* 20h */	virtual bool SetSize(size_type size) override;
		/* 24h */	virtual int GetPosition(PositionType positionType = PositionType::Begin) const override;
		/* 28h */	virtual bool SetPosition(int distance, PositionType positionType = PositionType::Begin) override;
		/* 2Ch */	virtual int GetAvailable() const override;

		/* 30h */	virtual int Read(void* pData, size_t nSize) override;
		/* 34h */	virtual bool Flush() override;
		/* 38h */	virtual int Write(const void* pData, size_t nSize) override;

		/* 3Ch */	virtual bool SetCompressedFormat(CompressedFormat format);
		/* 40h */	virtual bool SetBufferSize(size_t nOutputBufferSize);
		/* 44h */	virtual bool SetCompressionHint(int hint);

		/* 48h */	virtual bool Open(IStream* pOutputStream, int nHint);
	protected:
		/* 0Ch */	IStream* mpOutputStream;
		/* 10h */	bool mbOpen;
		/* 11h */	bool mbInited;
		/* 14h */	void* mpZLibStream; // z_stream_s*
		/* 18h */	CompressedFormat mFormat;
		/* 1Ch */	int mHint;
		/* 20h */	uint8_t* mpOutputBuffer;
		/* 24h */	size_t mnOutputBufferSize;
		/* 28h */	uint32_t mInputCRC;
		/* 2Ch */	size_t mInputSize;
	// destructor, private for ModAPI
	private:
		virtual void Dispose();
	};
	ASSERT_SIZE(StreamCompressionZLib, 0x30);

	namespace Addresses(StreamCompressionZLib)
	{
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(GetType);
		DeclareAddress(GetAccessFlags);
		DeclareAddress(GetState);
		DeclareAddress(Close);
		DeclareAddress(GetSize);
		DeclareAddress(SetSize);
		DeclareAddress(GetPosition);
		DeclareAddress(SetPosition);
		DeclareAddress(GetAvailable);
		DeclareAddress(Read);
		DeclareAddress(Flush);
		DeclareAddress(Write);
		DeclareAddress(SetCompressedFormat);
		DeclareAddress(SetBufferSize);
		DeclareAddress(SetCompressionHint);
		DeclareAddress(Open);
		// destructor, private for ModAPI
		DeclareAddress(Dispose);
	}

	class StreamDecompressionZLib : public IStream, public RefCountTemplateAtomic
	{
	public:

		static const uint32_t TYPE = 0x2420525;

	public:
		StreamDecompressionZLib(IStream* pInputStream);

		~StreamDecompressionZLib();

		/* 04h */	virtual int AddRef() override;
		/* 08h */	virtual int Release() override;

		/* 0Ch */	virtual uint32_t GetType() const override;
		/* 10h */	virtual AccessFlags GetAccessFlags() const override;
		/* 14h */	virtual FileError GetState() const override;
		/* 18h */	virtual bool Close() override;

		/* 1Ch */	virtual size_type GetSize() const override;
		/* 20h */	virtual bool SetSize(size_type size) override;
		/* 24h */	virtual int GetPosition(PositionType positionType = PositionType::Begin) const override;
		/* 28h */	virtual bool SetPosition(int distance, PositionType positionType = PositionType::Begin) override;
		/* 2Ch */	virtual int GetAvailable() const override;

		/* 30h */	virtual int Read(void* pData, size_t nSize) override;
		/* 34h */	virtual bool Flush() override;
		/* 38h */	virtual int Write(const void* pData, size_t nSize) override;

		/* 3Ch */	virtual bool SetCompressedFormat(CompressedFormat format);
		/* 40h */	virtual bool SetBufferSize(size_t nInputBufferSize);

		/* 44h */	virtual bool Open(IStream* pInputStream);
	protected:
		/* 0Ch */	IStream* mpInputStream;
		/* 10h */	CompressedFormat mFormat;
		/* 14h */	bool mbOpen;
		/* 15h */	bool mbEOF;
		/* 16h */	bool mbInited;
		/* 18h */	void* mpZLibStream; // z_stream_s*
		/* 1Ch */	uint8_t* mpInputBuffer;
		/* 20h */	size_t mnInputBufferSize;
	// destructor, private for ModAPI
	private:
		virtual void Dispose();
	};
	ASSERT_SIZE(StreamDecompressionZLib, 0x24);

	namespace Addresses(StreamDecompressionZLib)
	{
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(GetType);
		DeclareAddress(GetAccessFlags);
		DeclareAddress(GetState);
		DeclareAddress(Close);
		DeclareAddress(GetSize);
		DeclareAddress(SetSize);
		DeclareAddress(GetPosition);
		DeclareAddress(SetPosition);
		DeclareAddress(GetAvailable);
		DeclareAddress(Read);
		DeclareAddress(Flush);
		DeclareAddress(Write);
		DeclareAddress(SetCompressedFormat);
		DeclareAddress(SetBufferSize);
		DeclareAddress(Open);
		// destructor, private for ModAPI
		DeclareAddress(Dispose);
	}
}