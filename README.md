# Rendering Engine

OpenGL Rendering Engine that features Physically-Based Rendering (PBR), Image-Based Lighting (IBL), HDR skyboxes, and dynamic soft shadows. The engine also leverages Tessellation shaders to dynamically refine mesh detail at runtime and anti-aliasing to reduce visual artifacts, enabling the creation of visually compelling and realistic scenes.

![1](https://github.com/AmrHMorsy/Rendering-Engine/assets/56271967/fb130eef-aa40-4ffd-b9f1-203691813edb)


## Features

#### Physically-Based Rendering (PBR)

PBR techniques are employed to simulate realistic material properties. This approach ensures that the water surface in the simulation accurately reflects and refracts light, mimicking the way light interacts with natural water. The result is a stunningly realistic depiction of the ocean, complete with nuanced lighting effects.

![Screenshot 2024-02-28 at 00 29 36](https://github.com/AmrHMorsy/OpenGL-Rendering-Engine/assets/56271967/438d0f02-3d0f-4ce7-99f6-127c5a7c0b68)

#### Image-Based Lighting (IBL)

To further improve visual fidelity, Image-Based Lighting (IBL) is used. This technique utilizes real-world imagery to provide environmental lighting, ensuring that the engine's lighting conditions are based on actual atmospheric lighting. This results in richer reflections and more accurate illumination across the simulated ocean.

![3](https://github.com/AmrHMorsy/Rendering-Engine/assets/56271967/8afa773a-ec4d-40d5-9bc3-37c9c323e321)

#### Dynamic HDR Skybox 

An HDR (High Dynamic Range) Skybox is introduced to present a more dynamic and immersive sky. This feature captures the vast range of luminance of real-world skies, from the brightest clouds to the darkest nights, creating a more lifelike backdrop that enhances the visual experience.

![A](https://github.com/AmrHMorsy/OpenGL-Rendering-Engine/assets/56271967/3c22484b-c6e8-492f-987e-97bf198f6ee7)

#### Frustum Culling

This engine uses frustum culling to optimize the performance. By rendering only the elements that are within the player's field of view, it significantly reduces the processing load. This optimization ensures smooth and responsive performance, even when rendering complex scenes.

![1](https://github.com/AmrHMorsy/OpenGL-Rendering-Engine/assets/56271967/919fab79-e9b9-4de4-8646-cee6b5db78c4)


### Dynamic Soft Shadows

Features the calculation of soft shadows that dynamically change with the light source position, providing more realistic shadowing effects.

![7](https://github.com/AmrHMorsy/Rendering-Engine/assets/56271967/b89cf85a-225a-4529-ab44-aec8bfdf1408)

## Installation

1. Clone the repository:
```
git clone https://github.com/AmrHMorsy/Rendering-Engine-.git
```
2. Navigate to the project directory: 
```
cd Rendering_Engine
```
3. Create a build directory: 
```
mkdir build
```
4. Navigate to the build directory: 
```
cd build
```
5. Generate makefiles using cmake: 
```
cmake ../
```
6. compile using makefile: 
```
make
```
7. Run the program: 
```
./Rendering_Engine
```
<br>
