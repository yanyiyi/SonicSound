class TriggerMethod
{
    public:
        bool isTrigger;

        TriggerMethod() {
            isTrigger = false;
        }
        
        virtual void update(int) = 0;
        virtual bool isTrigger() = 0;
        virtual void reset() = 0;
}

