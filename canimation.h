#ifndef CANIMATION_H
#define CANIMATION_H


class CAnimation {

  public:
    CAnimation();
    void animate();
    void setFrameRate(int rate);
    void setCurrentFrame(int frame);
    int getCurrentFrame();
    void setMaxFrames(int noFrames);

  private:
    int currFrame;
    int frameInc;
    int frameRate;
    int oldTime;
    int maxFrames;
    bool oscillate;

};

#endif
