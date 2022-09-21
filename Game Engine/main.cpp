#include <iostream>
#include <d2d1.h>

#pragma comment(lib, "d2d1.lib")

template <class T> void SafeRelease(T** ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

int main()
{
	ID2D1Factory* pD2DFactory = NULL;
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);

	// Obtain the size of the drawing area.
	RECT rc;
	GetClientRect(GetConsoleWindow(), &rc);

	// Create a Direct2D render target          
	ID2D1HwndRenderTarget* pRT = NULL;
	hr = pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(GetConsoleWindow(), 
										D2D1::SizeU(rc.right - rc.left,rc.bottom - rc.top)), &pRT);

	ID2D1SolidColorBrush* pBlueBrush = NULL;
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &pBlueBrush);
	}

	pRT->BeginDraw();
	pRT->DrawRectangle(D2D1::RectF(rc.left + 100.0f, rc.top + 100.0f, rc.right - 100.0f, rc.bottom - 100.0f), pBlueBrush);
	hr = pRT->EndDraw();

	SafeRelease<ID2D1HwndRenderTarget>(&pRT);
	SafeRelease<ID2D1SolidColorBrush>(&pBlueBrush);
	SafeRelease<ID2D1Factory>(&pD2DFactory);

	return 0;
}