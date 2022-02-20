#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

static void Sleep(int seconds = 2){std::this_thread::sleep_for(std::chrono::seconds(seconds));}

extern bool GetLuck(int probability);

int main()
{	
	//Loading Font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){/*Error*/}
	
	//Loading Typewriter
	sf::Text Typewriter;
	Typewriter.setFont(font);
	Typewriter.setString("Pirel Ganteng");
	Typewriter.setCharacterSize(45);
	Typewriter.setFillColor(sf::Color::Green);
	
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Schizo Pirel Suite");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // Alternate between two strings
		if(GetLuck(500)){Typewriter.setString("Pirel Ganteng");}
		else{Typewriter.setString("Amogus");}
		
		// draw everything here...
        window.draw(Typewriter);

        // end the current frame
        window.display();
    }

    return 0;
}



