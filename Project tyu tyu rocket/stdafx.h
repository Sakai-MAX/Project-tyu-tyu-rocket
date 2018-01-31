#pragma once
#include <cstdio>
#include<chrono>

//Windows
#include<Windows.h>
#include<d3d11.h>
#ifdef _DEBUG
#include<crtdbg.h>
#endif

//DirectXTK
#include<CommonStates.h>
#include<SpriteBatch.h>
#include<SpriteFont.h>
#include<SimpleMath.h>
#include<Keyboard.h>
#include<GamePad.h>
#include <Mouse.h>
#include<WICTextureLoader.h>
#include <ctime>

//名前空間
using namespace DirectX;
using namespace SimpleMath;
using namespace std::chrono;

//ライブラリ関連付け
#pragma comment(lib, "d3d11.lib")