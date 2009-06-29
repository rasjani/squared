#ifndef CANIMATION_H
#define CANIMATION_H


class CAnimation {
    public: 
        enum animStyle {
            AnimStill,
            AnimLoop,
            AnimSingle,
            AnimSingleThrobbing,
            AnimThrobbing
        }; 
    
    public:
        CAnimation();
        void animate();
        void setFrameRate(int rate);
        void setCurrentFrame(int frame);
        int getCurrentFrame();
        void setMaxFrames(int noFrames);
        void setAnimStyle(animStyle animationStyle); 

    private:
        int currFrame;
        int frameInc;
        int frameRate;
        int oldTime;
        int maxFrames;
        bool oscillate;
        animStyle aStyle;

};

#endif
