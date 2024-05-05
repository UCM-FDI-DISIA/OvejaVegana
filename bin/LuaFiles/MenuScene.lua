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
                name = "UITextComponent",
                parameters = {                  
                    name = "playbutton",
                    font = "Mario",
                    caption = "PLAY",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,0.0,0.0} 
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
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbutton",
                    font = "Mario",
                    caption = "EXIT",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,0.0,0.0} 
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
                    position = {0.8, 0.1},
                    scale = {0.16, 0.05},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "mute",
                    font = "Mario",
                    caption = "MUTE",
                    zOrder = 3,
                    charHeight = 0.05,
                    color = {1.0,1.0,1.0} 
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
                    a = 0,
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1, 1, 1}                   
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