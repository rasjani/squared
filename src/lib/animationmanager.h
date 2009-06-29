#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H


class AnimationManager {
    public: 
        enum animStyle {
            AnimStill,
            AnimLoop,
            AnimSingle,
            AnimSingleThrobbing,
            AnimThrobbing
        }; 
    
    public:
        AnimationManager();
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
