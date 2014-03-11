using namespace std;

class newRect
{
	short x;
	short y;
	short h;
	short w;

	public:
		newRect();
		SDL_Rect& createNewRect(short, short, short, short);
};
