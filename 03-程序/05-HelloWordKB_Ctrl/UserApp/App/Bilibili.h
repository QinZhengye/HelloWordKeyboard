//
// Created by QZY on 2022/12/11.
//

#ifndef HELLOWORDKB_CTRL_BILIBILI_H
#define HELLOWORDKB_CTRL_BILIBILI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "UserApp.h"


void Bilibili_Init();


class CBilibili
{
public:
    uint32_t GetFansNum() {
        return fansNum;
    }
    uint32_t GetLikeNum() {
        return likeNum;
    }
    uint32_t GetTotalPlayNum() {
        return totalPlayNum;
    }
    uint32_t GetFollowNum() {
        return followNum;
    }

    void GetDate(uint32_t *_fans, uint32_t *_like, uint32_t *_total, uint32_t *_follow)
    {
        *_fans = fansNum;
        *_like = likeNum;
        *_total = totalPlayNum;
        *_follow = followNum;
    }

    void SetData(const uint32_t _fans, const uint32_t _like, const uint32_t _total, const uint32_t _follow)
    {
         fansNum = _fans;
         likeNum = _like;
         totalPlayNum = _total;
         followNum = _follow;
    }

private:
    uint32_t fansNum;       // 粉丝数
    uint32_t likeNum;       // 获点赞数
    uint32_t totalPlayNum;  // 视频总播放量
    uint32_t followNum;     // 关注数
};

extern CBilibili bilibili;

#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_BILIBILI_H
