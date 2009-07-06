#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H


class AnimationManager {
    friend class Surface;
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
        AnimationManager(int frames, animStyle style= AnimLoop);

        void animate();
        void setFrameRate(int rate);
        void setCurrentFrame(int frame);
        int getCurrentFrame();
        void setMaxFrames(int noFrames);
        void setAnimStyle(animStyle animationStyle); 
        void resetClass();

    protected:
        int currFrame;
        int frameInc;
        int frameRate;
        int oldTime;
        int maxFrames;
        animStyle aStyle;
    private:
        animStyle backup;

};

#endif // For ANIMATIONMANAGER_H
