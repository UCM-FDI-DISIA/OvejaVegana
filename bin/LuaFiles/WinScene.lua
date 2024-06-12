Entities={
    {
        name = "ExitButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.7},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },        
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbutton3",
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
        name = "MenuButton2",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.5},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },        
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "menubutton2",
                    font = "Mario",
                    caption = "MENU",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,0.0,0.0} 
                }
            },
            {
                name = "MenuButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "Winner",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.3, 0.1},
                    scale = {0.4, 0.25},
                    hidden = false     
                }
            },        
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "winner", 
                    material = "winner", 
                    zOrder = 1
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
                    name = "win",
                    color = {0.0, 1.0, 0.0},
                    offset = {0.0, 0.0, 0.0},
                    zOrder = 4
                }
            },
            {
                name = "AudioListenerComponent",
                parameters = {

                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audiowin",
                    path = "sonido_ganar.mp3",
                    onstart = true,
                    loop = true,
                    threed = false,
                    volume = 1,
                    groupchannel = "music"
                }
            }
        }
    }
}