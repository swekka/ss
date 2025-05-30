#include "toBeSorted/arc_managers/layout_arc_manager.h"

#include "d/d_heap.h"


LayoutArcManager *LayoutArcManager::sInstance;

LayoutArcManager::LayoutArcManager() {
    sInstance = this;
}

LayoutArcManager::~LayoutArcManager() {
    sInstance = nullptr;
}

void LayoutArcManager::init(EGG::Heap *heap) {
    mArcTable.init(16, &ArcCallbackHandler::sInstance, heap);
}

bool LayoutArcManager::loadLayoutArcFromDisk(const char *object, EGG::Heap *heap) {
    if (heap == nullptr) {
        heap = dHeap::layoutResHeap.heap;
    }
    return mArcTable.getArcOrLoadFromDisk(object, "Layout", 0, heap);
}

int LayoutArcManager::ensureLoaded1(const char *object) {
    return mArcTable.ensureLoadedMaybe2(object);
}

int LayoutArcManager::ensureLoaded2(const char *object) {
    return mArcTable.ensureLoadedMaybe(object);
}

bool LayoutArcManager::hasEntry(const char *object) {
    return mArcTable.hasEntry(object);
}

bool LayoutArcManager::decrement(const char *path) {
    return mArcTable.decreaseRefCount(path);
}

void *LayoutArcManager::getData(const char *oarcName, const char *fileName) {
    return mArcTable.getDataFromOarc(oarcName, fileName);
}

void *LayoutArcManager::getLoadedData(const char *path) {
    return mArcTable.getLoadedArcData(path);
}

bool LayoutArcManager::create(EGG::Heap *heap) {
    new (heap, 0x04) LayoutArcManager();

    if (GetInstance() == nullptr) {
        return false;
    }
    GetInstance()->init(heap);
    return true;
}
