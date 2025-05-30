#include "d/a/obj/d_a_obj_bird_sp.h"

#include "d/a/d_a_bird.h"
#include "d/col/c/c_cc_d.h"
#include "d/col/cc/d_cc_s.h"
#include "f/f_base.h"
#include "f/f_profile_name.h"
#include "m/m_mtx.h"

// clang-format off
dCcD_SrcSph dAcObjBirdSp_c::sCcSrc = {
    /* mObjInf */ {
        /* mObjAt */ {0, 2, {0, 0, 0}, 0, 0, 0, 0, 0, 0},
        // AT_TYPE_COMMON0 - AT_TYPE_WIND
        /* mObjTg */ {~(AT_TYPE_BUGNET | AT_TYPE_BEETLE | AT_TYPE_0x80000 | AT_TYPE_0x8000), 0x00000105, {0, 00, 0x407}, 0, 0},
        /* mObjCo */ {0x00004029}},
     /* mSphInf */ {1000.0f}
};
// clang-format on

SPECIAL_ACTOR_PROFILE(OBJ_BIRD_SP_UP, dAcObjBirdSp_c, fProfile::OBJ_BIRD_SP_UP, 0x260, 0, 1);

bool dAcObjBirdSp_c::createHeap() {
    return SUCCEEDED;
}

int dAcObjBirdSp_c::create() {
    CREATE_ALLOCATOR(dAcObjBirdSp_c);

    boundingBox.Set(mVec3_c(-2000, -2000, -2000), mVec3_c(2000, 2000, 2000));
    mCollider.Set(sCcSrc);
    mCollider.SetStts(mStts);
    mCollider.SetR(mScale.x * 1000.0f);

    return SUCCEEDED;
}
int dAcObjBirdSp_c::actorExecute() {
    /* if its colliding with Bird or Player */
    if (mCollider.ChkCoHit() && mCollider.GetCoActor() != nullptr &&
        (mCollider.GetCoActor()->profile_name == fProfile::BIRD ||
         mCollider.GetCoActor()->profile_name == fProfile::PLAYER)) {
        mVec3_c posChange(0, -0.2, 1.0);
        mMtx_c matrix;
        matrix.ZXYrotS(rotation);
        PSMTXMultVec(matrix.m, posChange, posChange);

        f32 angle = (position - dBird_c::getInstance()->position).dot(posChange);
        if (angle < 0.0f) {
            posChange = -posChange;
        }

        posChange *= 1000.0f;
        posChange += position;
        posChange -= dBird_c::getInstance()->position;
        dBird_c::getInstance()->accelerateTowards(posChange);
    }

    mCollider.SetC(position);
    dCcS::GetInstance()->Set(&mCollider);
    mWorldMtx.transS(position.x, position.y, position.z);
    mWorldMtx.ZXYrotM(rotation);

    return SUCCEEDED;
}

int dAcObjBirdSp_c::draw() {
    return SUCCEEDED;
}
