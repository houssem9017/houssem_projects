#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main()
  {
  int exit=0;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Surface *ecran = NULL; 
  SDL_Surface *background = NULL; 
  SDL_Event event;
  SDL_Rect bg;
  bg.x = 0;
  int l=0;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(1440,860, 32, SDL_HWSURFACE); 
  background = IMG_Load("greenbg.png");
  SDL_BlitSurface(background, NULL, ecran, &bg);  /*1440.2560*/
  SDL_Flip(ecran);
while(exit!=1)
{
while( SDL_PollEvent( &event ) )
{
switch(event.type)
    {case SDL_MOUSEBUTTONUP:
	switch(event.button.button)	
			{case SDL_BUTTON_WHEELUP: if(l!=0)     	l=l+20; break;	
			 case SDL_BUTTON_WHEELDOWN: if(l!=-1700)	l=l-20; break;				
	break;}
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_ESCAPE)
exit=1;
break;
}
  bg.y=l;
  SDL_BlitSurface(background, NULL, ecran, &bg);
  SDL_Flip(ecran);
}
}
 SDL_Quit();
 return 0;
  }
