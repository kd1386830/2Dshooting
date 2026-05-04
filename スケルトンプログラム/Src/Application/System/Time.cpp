#include "Time.h"
#include"../Scene/GameScene/GameScene.h"
#include"../Scene/GameScene/Object/BaseObject.h"

void Time::Init()
{
    m_Tex.Load("Texture/UI/Number.png");
    m_ColonTex.Load("Texture/UI/Colon.png");

    m_CountDownUI.m_Pos = { 0,0 };
    m_CountDownUI.m_Scale = 15;

    m_AliveMinTenUI.m_Pos = { -260,0 };
    m_AliveMinTenUI.m_Scale = 20;

    m_AliveMinOneUI.m_Pos = { -110,0 };
    m_AliveMinOneUI.m_Scale = 20;

    m_ColonUI.m_Pos = { 0,0 };
    m_ColonUI.m_Scale = 20;

    m_AliveSecTenUI.m_Pos = { 110,0 };
    m_AliveSecTenUI.m_Scale = 20;

    m_AliveSecOneUI.m_Pos = { 260,0 };
    m_AliveSecOneUI.m_Scale = 20;
}

void Time::Update()
{
    if (!m_GameStartFlg)
    {
        if (m_CountDown > 0)
        {
            m_CountDown --;

            if (m_CountDown <= 0)
            {
                m_CountDown = 0;
                m_GameStartFlg = true;
            }
        }
    }
    else
    {
        for (auto& obj : m_Owner->GetObjList())
        {
            if (obj->GetObjType() == BaseObject::ObjectType::Player)
            {
                if (obj->GetAliveFlg())
                {
                    m_CountUp++;
                }
                else
                {

                }
            }
        }
    }

    m_TotalSec = m_CountUp / 60;
    m_Minutes = m_TotalSec / 60;
    m_Seconds = m_TotalSec % 60;

    m_MinTens = m_Minutes / 10;
    m_MinOnes = m_Minutes % 10;

    m_SecTens = m_Seconds / 10;
    m_SecOnes = m_Seconds % 10;


    //カウントダウン
    m_CountDownUI.m_TransMat = Math::Matrix::CreateTranslation(m_CountDownUI.m_Pos.x, m_CountDownUI.m_Pos.y, 0);
    m_CountDownUI.m_ScaleMat = Math::Matrix::CreateScale(m_CountDownUI.m_Scale, m_CountDownUI.m_Scale, 0);
    m_CountDownUI.m_Mat = m_CountDownUI.m_ScaleMat * m_CountDownUI.m_TransMat;
    //カウントアップ
    //分の十の位
    m_AliveMinTenUI.m_TransMat = Math::Matrix::CreateTranslation(m_AliveMinTenUI.m_Pos.x, m_AliveMinTenUI.m_Pos.y, 0);
    m_AliveMinTenUI.m_ScaleMat = Math::Matrix::CreateScale(m_AliveMinTenUI.m_Scale, m_AliveMinTenUI.m_Scale, 0);
    m_AliveMinTenUI.m_Mat = m_AliveMinTenUI.m_ScaleMat * m_AliveMinTenUI.m_TransMat;
    //分の一の位
    m_AliveMinOneUI.m_TransMat = Math::Matrix::CreateTranslation(m_AliveMinOneUI.m_Pos.x, m_AliveMinOneUI.m_Pos.y, 0);
    m_AliveMinOneUI.m_ScaleMat = Math::Matrix::CreateScale(m_AliveMinOneUI.m_Scale, m_AliveMinOneUI.m_Scale, 0);
    m_AliveMinOneUI.m_Mat = m_AliveMinOneUI.m_ScaleMat * m_AliveMinOneUI.m_TransMat;
    //コロン
    m_ColonUI.m_TransMat = Math::Matrix::CreateTranslation(m_ColonUI.m_Pos.x, m_ColonUI.m_Pos.y, 0);
    m_ColonUI.m_ScaleMat = Math::Matrix::CreateScale(m_ColonUI.m_Scale, m_ColonUI.m_Scale, 0);
    m_ColonUI.m_Mat = m_ColonUI.m_ScaleMat * m_ColonUI.m_TransMat;
    //秒の十の位
    m_AliveSecTenUI.m_TransMat = Math::Matrix::CreateTranslation(m_AliveSecTenUI.m_Pos.x, m_AliveSecTenUI.m_Pos.y, 0);
    m_AliveSecTenUI.m_ScaleMat = Math::Matrix::CreateScale(m_AliveSecTenUI.m_Scale, m_AliveSecTenUI.m_Scale, 0);
    m_AliveSecTenUI.m_Mat = m_AliveSecTenUI.m_ScaleMat * m_AliveSecTenUI.m_TransMat;
    //秒の一の位
    m_AliveSecOneUI.m_TransMat = Math::Matrix::CreateTranslation(m_AliveSecOneUI.m_Pos.x, m_AliveSecOneUI.m_Pos.y, 0);
    m_AliveSecOneUI.m_ScaleMat = Math::Matrix::CreateScale(m_AliveSecOneUI.m_Scale, m_AliveSecOneUI.m_Scale, 0);
    m_AliveSecOneUI.m_Mat = m_AliveSecOneUI.m_ScaleMat * m_AliveSecOneUI.m_TransMat;
}

void Time::Draw()
{
    if (!m_GameStartFlg)
    {
        SHADER.m_spriteShader.SetMatrix(m_CountDownUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle((8 * (m_CountDown / 60) + 8), 0, 8, 8), 1.0f);
    }
    else
    {
        //分の十の位
        SHADER.m_spriteShader.SetMatrix(m_AliveMinTenUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(8 * m_MinTens, 0, 8, 8), 0.3f);
        //分の一の位
        SHADER.m_spriteShader.SetMatrix(m_AliveMinOneUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(8 * m_MinOnes, 0, 8, 8), 0.3f);
        //コロン
        SHADER.m_spriteShader.SetMatrix(m_ColonUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_ColonTex, Math::Rectangle(0, 0, 8, 8), 0.3f);
        //秒の十の位
        SHADER.m_spriteShader.SetMatrix(m_AliveSecTenUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(8 * m_SecTens, 0, 8, 8), 0.3f);
        //秒の一の位
        SHADER.m_spriteShader.SetMatrix(m_AliveSecOneUI.m_Mat);
        SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(8 * m_SecOnes, 0, 8, 8), 0.3f);
    }
}

void Time::StaartCountDown(float time)
{
	m_CountDown = time * 60;
	m_CountUp = 0.0f;
	m_GameStartFlg = false;
}
