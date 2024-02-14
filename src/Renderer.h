#include "Camera.h"




class Renderer{
    
private:
    
    int fps ;
    Shadow * shadow ;
    Light * light ;
    Skybox * skybox ;
    Plane * ground ;
    Camera * camera ;
    GLFWwindow * window ;
    float fps_time, time ;
    Model * piano, * bench, * house, * portrait ; 

public:
    
    Renderer( GLFWwindow * window_, progressbar * bar) ;
    void set() ;
    void play_music() ;
    void start_game_loop() ;
    void render_scene() ;
    void render_shadow() ;
    void handle_events() ;
    void update_view() ;
    void calculate_fps() ;
    void generate_error( std::string error_msg ) ;
    ~Renderer() ;

} ;
