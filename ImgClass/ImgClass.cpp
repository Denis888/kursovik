// ImgClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define BYTE unsigned __int8
#define WORD unsigned __int16
#define DWORD unsigned __int32

struct RGBTRIPLE
{
	BYTE Blue;
	BYTE Green;
	BYTE Red;
};
struct RGBQUAD
{
	BYTE Blue;
	BYTE Green;
	BYTE Red;
	BYTE Reserved;
};
struct BITMAPFILEHEADER
{
	WORD Type;
	DWORD Size;
	WORD Reserved1;
	WORD Reserved2;
	DWORD OffsetBits;
};
struct BITMAPINFOHEADER
{
	DWORD Size;
	DWORD Width;
	DWORD Height;
	WORD Planes;
	WORD BitCount;
	DWORD Compression;
	DWORD SizeImage;
	DWORD XPelsPerMeter;
	DWORD YPelsPerMeter;
	DWORD ColorUsed;
	DWORD ColorImportant;
};
class Image {
private:
	BITMAPINFOHEADER BMInfoHeader;
	RGBTRIPLE **Rgbtriple;
	RGBQUAD **Rgbquad;
public:
	Image(char *fileName);
	Image(char Mode, unsigned short BitCount, int Width, int Height);
	Image(const Image &i);
	Image();

	~Image();

	int loadimage(char *fileName);
	void writeimage(char *fileName);

	Image operator = (Image Inp);
};

Image::Image(char Mode, unsigned short BitCount, int Width, int Height)
{
	BMInfoHeader.Size = 40;
	BMInfoHeader.Width = Width;
	BMInfoHeader.Height = Height;
	BMInfoHeader.Planes = 1;
	BMInfoHeader.BitCount = BitCount;
	BMInfoHeader.Compression = 0;
	BMInfoHeader.SizeImage = BitCount * Width * Height;
	BMInfoHeader.XPelsPerMeter = 0;
	BMInfoHeader.YPelsPerMeter = 0;
	BMInfoHeader.ColorUsed = 0;
	BMInfoHeader.ColorImportant = 0;
	if (BMInfoHeader.BitCount == 24)
	{
		Rgbtriple = new RGBTRIPLE*[BMInfoHeader.Height];
		for (int i = 0; i < BMInfoHeader.Height; i++)
		{
			Rgbtriple[i] = new RGBTRIPLE[BMInfoHeader.Width];
		};
		for (int i = 0; i < BMInfoHeader.Height; i++)
		{
			for (int j = 0; j < BMInfoHeader.Width; j++)
			{
				Rgbtriple[i][j].Red = Mode;
				Rgbtriple[i][j].Green = Mode;
				Rgbtriple[i][j].Blue = Mode;
			};
		};
	};
	if (BMInfoHeader.BitCount == 32)
	{
		Rgbquad = new RGBQUAD*[BMInfoHeader.Height];
		for (int i = 0; i < BMInfoHeader.Height; i++)
		{
			Rgbquad[i] = new RGBQUAD[BMInfoHeader.Width];
		};
		for (int i = 0; i < BMInfoHeader.Height; i++)
		{
			for (int j = 0; j < BMInfoHeader.Width; j++)
			{
				Rgbquad[i][j].Red = Mode;
				Rgbquad[i][j].Green = Mode;
				Rgbquad[i][j].Blue = Mode;
				Rgbquad[i][j].Reserved = 0;
			};
		};
	};
};

Image::Image()
{
	BMInfoHeader.Size	 = NULL;
	BMInfoHeader.Width	 = NULL;
	BMInfoHeader.Height	 = NULL;
	BMInfoHeader.Planes	 = NULL;
	BMInfoHeader.BitCount	 = NULL;
	BMInfoHeader.SizeImage	 = NULL;
	BMInfoHeader.Compression = NULL;
	BMInfoHeader.ColorUsed	 = NULL;
	BMInfoHeader.XPelsPerMeter	 = NULL;
	BMInfoHeader.YPelsPerMeter	 = NULL;
	BMInfoHeader.ColorImportant	 = NULL;
	Rgbtriple = NULL;
	Rgbquad = NULL;
};

int main()
{
	return 0;
}
