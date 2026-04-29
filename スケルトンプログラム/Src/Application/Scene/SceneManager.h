#pragma once

class BaseScene;

class SceneManager
{
public:

	enum SceneType
	{
		Title,
		Game,
		Result
	};

	void Init();
	void Update();
	void Draw();

	//次のシーンを予約する
	void SetNextScene(SceneType _nextScene)
	{
		m_nextSceneType = _nextScene;
	}

	//現在のシーンを取得する
	SceneType GetCurrentSceneType()const
	{
		return m_currentSceneType;
	}

private:

	//保守性を高めるために、他で呼べないようにする
	void Release();
	void ChangeScene(SceneType _sceneType);

	//変数
	std::shared_ptr<BaseScene> m_currentScene;			//現在のシーンを管理しているポインタ
	SceneType m_currentSceneType = SceneType::Title;	//現在のシーンの種類
	SceneType m_nextSceneType = m_currentSceneType;	//次のシーンの種類

private:

	SceneManager() {}
	~SceneManager() { Release(); }

public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}
};