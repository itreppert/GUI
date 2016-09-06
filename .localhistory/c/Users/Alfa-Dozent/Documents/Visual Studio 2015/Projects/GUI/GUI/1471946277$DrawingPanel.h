#pragma once
public ref class DrawingPanel :public System::Windows::Forms::Panel
{
public:

	DrawingPanel()
	{
	}

	virtual ~DrawingPanel()
	{
	}



	void drawHouse(Graphics^ graphics, int startPositionX, int startPositionY, double scaleFactorX, double scaleFactorY)
	{
		System::Drawing::Pen^ penBlue = gcnew System::Drawing::Pen(System::Drawing::Color::Blue);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 300, 0, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 100, 200, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 100, 200, 300, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 300, 0, 300, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 100, 100, 20, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 100, 20, 200, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 100, 20, 300, 20, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 300, 20, 400, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 400, 100, 200, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 400, 300, 400, 100, scaleFactorX, scaleFactorY);
		drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 300, 400, 300, scaleFactorX, scaleFactorY);
	}

	void drawSpecialLine(Graphics^ graphics, Pen^ pen, float startPositionX, float startPositionY, float x1, float y1, float x2, float y2, float scaleFactorX, float scaleFactorY)
	{
		graphics->DrawLine(pen, startPositionX + x1 * scaleFactorX, startPositionY + y1 * scaleFactorY, startPositionX + x2 * scaleFactorX, startPositionY + y2 * scaleFactorY);

	}

};

