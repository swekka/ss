#ifndef NW4R_TYPES_H
#define NW4R_TYPES_H
#include <common.h>

#define NW4R_BYTEORDER_BIG 0xFEFF
#define NW4R_BYTEORDER_LITTLE 0xFFFE

#define NW4R_VERSION(major, minor) ((major & 0xFF) << 8 | minor & 0xFF)

#ifdef NW4R_LITTLE_ENDIAN
#define NW4R_BYTEORDER_NATIVE NW4R_BYTEORDER_LITTLE
#else
#define NW4R_BYTEORDER_NATIVE NW4R_BYTEORDER_BIG
#endif

#define NW4R_LIB_VERSION(NAME, ORIGINAL_DATE, ORIGINAL_TIME, ORIGINAL_CWCC)                                            \
    const char *NW4R_##NAME##_Version_ =                                                                               \
        "<< NW4R    - " #NAME " \tfinal   build: " ORIGINAL_DATE " " ORIGINAL_TIME " (" ORIGINAL_CWCC ") >>"

#if defined(CHAR_BIT)
# define CHAR_BIT_	CHAR_BIT
#else
# define CHAR_BIT_	8 // most common; default
#endif

// offset in bytes
#define NW4R_BYTE_(byte_, offset_)	\
	(static_cast<unsigned char>(byte_) << CHAR_BIT_ * (offset_))

#define NW4R_FILE_VERSION(MAJOR, MINOR)	\
	(NW4R_BYTE_(MAJOR, 1) | NW4R_BYTE_(MINOR, 0))

#define NW4R_FOUR_BYTE(A, B, C, D)	\
	(NW4R_BYTE_(A, 3) | NW4R_BYTE_(B, 2) | NW4R_BYTE_(C, 1) | NW4R_BYTE_(D, 0))

namespace nw4r {
namespace ut {
namespace detail {

struct RuntimeTypeInfo;
struct ResFontBase;

} // namespace detail

template <typename T>
struct AutoLock;
struct AutoInterruptLock;
struct BinaryBlockHeader;
struct BinaryFileHeader;
struct CharStrmReader;
struct CharWidths;
struct CharWriter;
struct Color;
struct DvdFileStream;
struct DvdLockedFileStream;
struct FileStream;
struct Font;
struct Glyph;
struct IOStream;
template <typename T, int Ofs>
struct LinkList;
struct List;
struct NandFileStream;
template <typename T>
struct PrintContext;
struct Rect;
struct ResFont;
struct RomFont;
template <typename T>
struct TagProcessorBase;
template <typename T>
struct TextWriterBase;

} // namespace ut

namespace ef {
struct DrawOrder;
struct DrawInfo;
struct DrawStrategy;
struct DrawStrategyImpl;
struct DrawStrategyBuilder;
struct Effect;
struct EffectSystem;
struct EffectProject;
struct Emitter;
struct EmitterDrawSetting;
struct EmitFormBuilder;
struct ResEmitter;
struct EmitterResource;
struct EmitterForm;
struct EmitterInheritSetting;
struct Particle;
struct ParticleManager;
struct MemoryManager;
struct MemoryManagerBase;
} // namespace ef

namespace math {

struct VEC2;
struct VEC3;
struct MTX33;
struct MTX34;
struct MTX44;
struct QUAT;
struct PLANE;
struct AABB;
struct FRUSTUM;

} // namespace math

namespace snd {

struct AxVoice;
struct FxBase;
struct SoundPlayer;
struct SoundHandle;
struct SeqSoundHandle;
struct SoundArchive;
struct SoundArchivePlayer;
struct Sound3DActor;
struct Sound3DListener;
struct Sound3DManager;
struct SoundHandle;
struct StrmSoundHandle;
struct WaveSoundHandle;

namespace detail {

struct AxfxImpl;
struct AxManager;
struct AxVoiceManager;
struct ExternalSoundPlayer;

struct BasicSound;
struct BasicPlayer;
struct ChannelManager;
struct SeqSound;
struct SeqPlayer;
struct MmlParser;
struct MmlSeqTrack;
struct SeqTrack;
struct SeqTrackAllocator;
template <typename T>
struct SoundInstanceManager;
struct StrmBufferPool;
struct StrmSound;
struct NoteOnCallback;
struct PlayerHeap;
struct SoundArchiveFileReader;
struct SoundThread;
struct WaveSound;
struct StrmPlayer;
struct WsdPlayer;
} // namespace detail
} // namespace snd

namespace g3d {
struct AnmObjVis;
struct AnmObjVisNode;
struct AnmObjVisOR;
struct AnmObjVisRes;
struct AnmObj;
struct AnmObjChr;
struct FuncObjCalcWorld;
struct AnmScn;
struct AnmScnRes;
struct CameraAnmResult;
struct ChrAnmResult;
struct Draw1Mat1ShpSwap;
struct DrawResMdlReplacement;
struct FogAnmResult;
struct ResFile;
struct ResMdl;
struct ResPltt;
struct ResTex;
struct ResTexSrt;
struct ResMat;
struct ResTexPlttInfo;
struct ResShp;
struct ResFog;
struct ResAnmChr;
struct ResAnmVis;
struct ResAnmClr;
struct ResAnmTexPat;
struct ResAnmTexSrt;
struct ResAnmShp;
struct ResAnmScn;
struct ResAnmFog;
struct ResAnmCamera;
struct ResVtxPos;
struct ResVtxNrm;
struct ResVtxClr;
struct ResVtxTexCoord;
struct ClrAnmResult;
struct TexPatAnmResult;
struct TexSrtAnmResult;
struct ScnMdl1Mat1Shp;
struct TexSrt;
struct TexSrtTypedef;
struct LightObj;
struct LightAnmResult;
struct LightSet;
struct LightSetting;
struct LightSetData;
struct AmbLightObj;
struct AmbLightAnmResult;
struct Fog;
struct ScnRoot;
struct ScnProc;
struct ScnLeaf;
struct ScnObj;
struct ScnRfl;
struct ScnGroup;
struct ScnMdlSimple;
struct ScnMdl;
struct IScnObjGather;
struct IScnObjCallback;

namespace G3DState {
struct IndMtxOp;
}
} // namespace g3d

namespace lyt {
struct Size;

namespace detail {
struct PaneBase;
struct TexCoordAry;
} // namespace detail

namespace res {
struct Group;
struct Pane;
struct Bounding;
struct AnimationBlock;
struct BinaryFileHeader;
} // namespace res

struct Group;
struct GroupContainer;
struct Pane;
struct DrawInfo;
struct AnimResource;
struct AnimTransform;
struct AnimTransformBasic;
struct AnimationLink;
struct ResourceAccessor;
struct ArcResourceAccessor;
struct FontRefLink;
struct Material;
struct Layout;
struct Bounding;
struct ResBlockSet;
struct TexMap;
} // namespace lyt
} // namespace nw4r

#endif
