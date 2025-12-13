#ifndef DETECTOR_H
#define DETECTOR_H

class Detector {
public:
    Detector();
    virtual ~Detector();

    void setNext(Detector* next);
    void handle();

protected:
    virtual bool detect() = 0;

private:
    Detector* m_next;
};

#endif
