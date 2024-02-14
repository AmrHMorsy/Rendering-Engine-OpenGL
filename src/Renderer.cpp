#include "Renderer.h"
#define PROGRESS_BARS_STEP 10




Renderer::Renderer( GLFWwindow * window_, progressbar * bar): fps(0), fps_time(0), window(window_)
{
    light = new Light(window) ;
    camera = new Camera() ;
    shadow = new Shadow( window, light->get_projection(), light->get_view() ) ;
    piano = new Model( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar, {"../assets/Piano/Piano/Albedo.png", "../assets/Piano/Piano/AO.png", "../assets/Piano/Piano/Normal.png", "../assets/Piano/Piano/Roughness.png", "../assets/Piano/Piano/Displacement.png", "../assets/Piano/Piano/Metallic.png"}, "../assets/Piano/Piano/Piano.obj", light->get_projection(), light->get_view()) ;
    house = new Model( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar, {"../assets/House/Albedo.png", "../assets/House/AO.png", "../assets/House/Normal.png", "../assets/House/Roughness.png", "../assets/House/Displacement.png", "../assets/House/Metallic.png"}, "../assets/House/House.obj", light->get_projection(), light->get_view() ) ;
    bench = new Model( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar, {"../assets/Piano/Bench/Albedo.png", "../assets/Piano/Bench/AO.png", "../assets/Piano/Bench/Normal.png", "../assets/Piano/Bench/Roughness.png", "../assets/Piano/Bench/Displacement.png", "../assets/Piano/Bench/Metallic.png"}, "../assets/Piano/Bench/Bench.obj", light->get_projection(), light->get_view()) ;
    portrait = new Model( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar, {"../assets/Portrait/Albedo.png", "../assets/Portrait/AO.png", "../assets/Portrait/Normal.png", "../assets/Portrait/Roughness.png", "../assets/Portrait/Displacement.png", "../assets/Portrait/Metallic.png"}, "../assets/Portrait/Portrait.obj", light->get_projection(), light->get_view()) ;
    ground = new Plane( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar, {"../assets/Ground/Albedo.png", "../assets/Ground/AO.png", "../assets/Ground/Normal.png", "../assets/Ground/Roughness.png", "../assets/Ground/Displacement.png", "../assets/Ground/Metallic.png"}, "../assets/Ground/Ground.obj", light->get_projection(), light->get_view()) ;
    skybox = new Skybox( camera->get_view(), camera->get_projection(), camera->get_camera_position(), bar) ;
}

void Renderer::set()
{
    piano->set(skybox) ;
    bench->set(skybox) ;
    house->set(skybox) ;
    portrait->set(skybox) ;
    ground->set(skybox) ;
}

void Renderer::play_music()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        generate_error("Failed to open audio") ;
    Mix_Music * music = Mix_LoadMUS("../assets/music/Background.mp3");
    if (!music)
        generate_error("Failed to load music") ;
    Mix_VolumeMusic(MIX_MAX_VOLUME / 6) ;
    Mix_PlayMusic(music, -1) ;
    std::cout << std::endl ;
    Mix_Chunk *soundEffect = Mix_LoadWAV("../assets/music/Waves.mp3");
    if (!soundEffect)
        generate_error("Failed to load sound effect");
    Mix_VolumeChunk(soundEffect, MIX_MAX_VOLUME / 50);
    Mix_PlayChannel(-1, soundEffect, -1); // Play once on any free channel
}

void Renderer::start_game_loop()
{
    time = glfwGetTime() ;
    update_view() ;
    while( !glfwWindowShouldClose(window) ){
        render_shadow() ;
        render_scene() ;
        glfwSwapBuffers(window) ;
        handle_events() ;
        calculate_fps() ;
    }
}

void Renderer::render_shadow()
{
    shadow->render() ;
//    ground->shade(shadow->get_shader_program()) ;
    piano->shade(shadow->get_shader_program()) ;
    portrait->shade(shadow->get_shader_program()) ;
    house->shade(shadow->get_shader_program()) ;
    bench->shade(shadow->get_shader_program()) ;
    shadow->reset() ;
}

void Renderer::render_scene()
{
    skybox->activate() ;
    skybox->render() ;
//    ground->shade(shadow) ;
    piano->shade(shadow) ;
    portrait->shade(shadow) ;
    house->shade(shadow) ;
    bench->shade(shadow) ;
}

void Renderer::handle_events()
{
    glfwPollEvents() ;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        camera->look_around(false,false,true,false) ;
        update_view() ;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        camera->look_around(false,false,false,true) ;
        update_view() ;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        camera->look_around(true,false,false,false) ;
        update_view() ;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        camera->look_around(false,true,false,false) ;
        update_view() ;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera->move() ;
        update_view() ;
    }
}

void Renderer::update_view()
{
    skybox->update_view( camera->get_view(), camera->get_camera_position() ) ;
    piano->update_view( camera->get_camera_position(), camera->get_view() ) ;
    bench->update_view( camera->get_camera_position(), camera->get_view() ) ;
    house->update_view( camera->get_camera_position(), camera->get_view() ) ;
    portrait->update_view( camera->get_camera_position(), camera->get_view() ) ;
    //ground->update_view( camera->get_camera_position(), camera->get_view() ) ;
}

void Renderer::calculate_fps()
{
    fps++ ;
    if( glfwGetTime() - static_cast<float>(fps_time) >= 1.0 ){
        std::cout << "FPS: \033[1;31m" << fps << "\033[0m" << '\r' << std::flush ;
        fps = 0 ;
        fps_time += 1.0 ;
    }
}

void Renderer::generate_error( std::string error_msg )
{
    std::cout << "\033[1;31m" << error_msg << "\033[0m" << std::endl;
    exit(1) ;
}

Renderer::~Renderer()
{
    delete portrait ;
    portrait = NULL ;
    delete house ;
    house = NULL ;
    delete light ;
    light = NULL ;
    delete ground ;
    ground = NULL ;
    delete bench ;
    bench = NULL ; 
    delete piano ;
    piano = NULL ;
    delete camera ;
    camera = NULL ;
    delete skybox ;
    skybox = NULL ;
}
