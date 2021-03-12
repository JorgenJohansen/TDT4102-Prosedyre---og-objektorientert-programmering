#include "Simple_window.h"
#include "Emoji.h"
#include "face.h"
#include "emptyFace.h"
#include "faces.h"
#include "tests.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

void drawAllEmojies(int x, int y, Graph_lib::Window& win){
	Vector_ref<Emoji> emojis;
	//lager emojiene
	SmileyFace smiley{Point{x,y}, emojiRadius};
	SadFace sadly{Point{x + emojiRadius,y}, emojiRadius};
	AngryFace angry{Point{x + 2 * emojiRadius,y}, emojiRadius};
	WinkyFace winky{Point{x + 3 * emojiRadius,y}, emojiRadius};
	SurprisedFace surprisy{Point{x + 4 * emojiRadius,y}, emojiRadius};

	//legger dem til vektoren
	emojis.push_back(smiley);
	emojis.push_back(sadly);
	emojis.push_back(angry);
	emojis.push_back(winky);
	emojis.push_back(surprisy);

	for(unsigned int i = 0; i < emojis.size(); i++){
		emojis[i].attach_to(win);
	}
	//win.wait_for_button();
	
}


int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/
	//Lager 2 variabler slik at vi havner
	//på midten av skjermen
	int x = xmax/2;
	int y = ymax/2;
	//EmptyFace face{Point{x,y}, emojiRadius};
	//Bruker medlemsfunksjonen til emptyface
	//face.attach_to(win);
	// SmileyFace smiley{Point{x,y}, emojiRadius};
	// smiley.attach_to(win);

	// SadFace sadly{Point{x+2*emojiRadius,y}, emojiRadius};
	// sadly.attach_to(win);

	// AngryFace angry{Point{x+4*emojiRadius,y}, emojiRadius};
	// angry.attach_to(win);

	// WinkyFace winky{Point{x+6*emojiRadius,y},emojiRadius};
	// winky.attach_to(win);

	// SurprisedFace surprisy{Point{x+8*emojiRadius,y},emojiRadius};
	// surprisy.attach_to(win);

	// Vector_ref<Emoji> emojis;
	// //lager emojiene
	// SmileyFace smiley{Point{x,y}, emojiRadius};
	// SadFace sadly{Point{x +3 * emojiRadius,y}, emojiRadius};
	// AngryFace angry{Point{x + 6 * emojiRadius,y}, emojiRadius};
	// WinkyFace winky{Point{x + 9 * emojiRadius,y}, emojiRadius};
	// SurprisedFace surprisy{Point{x + 12 * emojiRadius,y}, emojiRadius};

	// //legger dem til vektoren
	// emojis.push_back(smiley);
	// emojis.push_back(sadly);
	// emojis.push_back(angry);
	// emojis.push_back(winky);
	// emojis.push_back(surprisy);

	// for(unsigned int i = 0; i < emojis.size(); i++){
	// 	emojis[i].attach_to(win);
	// }

	//drawAllEmojies(x,y,win);
	testAnimal();
	

	win.wait_for_button();
}
