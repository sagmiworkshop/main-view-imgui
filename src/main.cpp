#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glad/glad.h> // Use GLAD to load OpenGL functions
#include <iostream>
#include <stdexcept> // For std::runtime_error

int main() {
    // Main Try Block
    try {
        // SDL Initialization
        if (SDL_Init(SDL_INIT_VIDEO)) {
            throw std::runtime_error("SDL Initialization failed: " + std::string(SDL_GetError()));
        }

        // Create SDL Window with OpenGL context
        SDL_Window *window = SDL_CreateWindow("Main Window",
                                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                              800, 600,
                                              SDL_WINDOW_OPENGL);

        if (!window) {
            throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
        }

        // Create OpenGL context
        SDL_GLContext glContext = SDL_GL_CreateContext(window);
        if (!glContext) {
            throw std::runtime_error("Failed to create OpenGL context: " + std::string(SDL_GetError()));
        }

        // Initialize GLAD to load OpenGL functions
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD!");
        }

        // Print OpenGL version to confirm it's working
        std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

        SDL_Event event;
        bool runningStatus = true;
 
        // Main event loop
        while (runningStatus) {
            // Poll events
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    runningStatus = false; // Set runningStatus to false when the window is closed
                }
            }

            // OpenGL rendering code would go here (e.g., clearing the screen, etc.)
            glClear(GL_COLOR_BUFFER_BIT); // Clear the screen (Optional: specify the color first with glClearColor)
            SDL_GL_SwapWindow(window);   // Swap buffers
        }

        // Cleanup
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
