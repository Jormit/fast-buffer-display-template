# fast-buffer-display-template
Template application using sdl to blit an rgb array to the screen. Example usage to draw onto buffer.
```cpp
for (long i = 0; i < 400000; i++) {
    frameBuffer[i].red = (float)(i % 1000)/1000.0f * 255;
    frameBuffer[i].green = (float)(i/1000 % 400)/400.0f * 255;
    frameBuffer[i].blue = (float)(1000 - (i % 1000))/1000.0f * 255;
}
```
Produces fully responsive window.
![img](test.png)
