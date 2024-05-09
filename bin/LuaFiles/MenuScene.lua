Entities={
    {
        name = "PlayButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.4},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "play", 
                    material = "play", 
                    zOrder = 1
                }
            },
            {
                name = "PlayButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "ExitButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.6},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "exit", 
                    material = "exit", 
                    zOrder = 1
                }
            },
            {
                name = "ExitButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "MusicButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.9, 0.03},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "music", 
                    material = "music", 
                    zOrder = 1
                }
            },
            {
                name = "MusicButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "Camera",
        components = {
            {
                name = "TransformComponent",
                parameters = {                   
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1.0, 1.0, 1.0}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {
                    name = "menu",
                    color = {0.1, 1.0, 0.1},
                    offset = {0.0, 0.0, 0.0},
                    zOrder = 0
                }
            }
        }
    }
}