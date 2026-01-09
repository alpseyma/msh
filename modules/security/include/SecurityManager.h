#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

class SecurityManager {
public:
    static SecurityManager& instance();

    void arm();
    void disarm();
    bool isArmed() const;

    // Detection zincirini çalıştırır; olay varsa alarm tetikler.
    void runOnce();

private:
    SecurityManager();
    SecurityManager(const SecurityManager&);
    SecurityManager& operator=(const SecurityManager&);

    bool m_armed;
};

#endif
