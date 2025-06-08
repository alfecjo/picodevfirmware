#ifndef I2CSETUP_HPP
#define I2CSETUP_HPP

class I2cSetup {
    
public:
    I2cSetup();  // Construtor que já inicializa
    void init(); // Ou você pode inicializar depois, se quiser mais controle

private:
    static constexpr uint SDA_PIN = 14;
    static constexpr uint SCL_PIN = 15;
    static constexpr uint FREQUENCY = 400000;
};

#endif
