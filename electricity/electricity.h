#pragma once
#include <string>

class Object;

/// <summary>
/// Полюс устройства.
/// К одному полюсу может быть подключен один любой другой полюс этого же
/// устройства, или же любой полюс любого другого устройства.
/// 
/// У каждого полюса есть своё название, которое получает значение по умолчанию
/// при создании устройства, но может быть изменено позднее.
/// </summary>
struct Pole {
    /// <summary>
    /// Название полюса.
    /// Должно быть уникальным в пределах устройства.
    /// </summary>
    std::string name;

    /// <summary>
    /// Устройство, подключенное к данному полюсу.
    /// Может совпадать с устройством, содержащим данный полюс, при условии, что соединяются
    /// два разных полюса.
    /// Значение <c>nullptr</c> означает, что к данному полюсу ничего не подключено.
    /// </summary>
    Object* connectedObject;

    /// <summary>
    /// Полюс устройства, к которому подключен данный полюс.
    /// </summary>
    std::string connectedObjectPole;

    Pole(const std::string& name_) : name(name_), connectedObject(nullptr) {}
};

/// <summary>
/// Электротехническое устройство.
/// Имеет произвольное неотрицательное количество полюсов (<see cref="Pole"/>),
/// через которые может соединяться с другими устройствами.
/// </summary>
class Object {
    std::string name;

protected:
    Object(const std::string& name_) : name(name_) {}

    /// <summary>
    /// Возвращает полюс по внутреннему индексу устройства.
    /// </summary>
    /// <param name="idx">Индекс полюса, от <c>0</c> до значения, возвращаемого <see cref="getPoleCount()"/>.</param>
    /// <returns>Полюс с указанным индексом, или <c>nullptr</c>, если такой полюс не существует.</returns>
    Pole* getPole(size_t idx) {
        if (getPole("A" + std::to_string(idx)))
            return getPole("A" + std::to_string(idx));
        return nullptr; 
    }

    /// <summary>
    /// Возвращает полюс по внутреннему индексу устройства.
    /// </summary>
    /// <param name="idx">Индекс полюса, от <c>0</c> до значения, возвращаемого <see cref="getPoleCount()"/>.</param>
    /// <returns>Полюс с указанным индексом, или <c>nullptr</c>, если такой полюс не существует.</returns>
    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}

    const std::string& getName() const { return name; }
    void getName(const std::string &newName) { name = newName; }

    /// <summary>
    /// Возвращает полюс по имени.
    /// </summary>
    /// <param name="name">Имя полюса.</param>
    /// <returns>Полюс с указанным именем, или <c>nullptr</c>, если такой полюс не существует.</returns>
    Pole* getPole(const std::string& name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }

    /// <summary>
    /// Возвращает полюс по имени.
    /// </summary>
    /// <param name="name">Имя полюса.</param>
    /// <returns>Полюс с указанным именем, или <c>nullptr</c>, если такой полюс не существует.</returns>
    virtual const Pole* getPole(const std::string& name) const = 0;

    /// <returns>Количество полюсов в текущем устройстве.</returns>
    virtual size_t getPoleCount() const = 0;

    /// <summary>
    /// Проверяет, связаны ли два указанных устройства напрямую через какую-либо пару их полюсов.
    /// </summary>
    /// <param name="other">Устройство, наличие прямой связи с которым проверяется.</param>
    /// <returns><c>true</c> если устройства связаны напрямую, <c>false</c> в противном случае.</returns>
    bool isConnectedTo(const Object& other) const;

    /// <summary>
    /// Соединяет указанные полюса текущего и указанного устройства.
    /// Если к этим полюсам было что-то подключено, то такая связь разрушается.
    /// </summary>
    /// <param name="poleName">Название подключаемого полюса текущего устройства</param>
    /// <param name="other">Устройство, которое связывается с текущим.</param>
    /// <param name="otherPoleName">Название подключаемого полюса другого устройства</param>
    /// <returns><c>true</c> если устройства удалось связать, <c>false</c> в противном случае.</returns>
    /// <remarks>
    /// Может использоваться для связи устройства с самим собой.
    /// В этом случае в качестве <paramref name="other"/> следует передать то же устройство,
    /// для которого вызывается этот метод.
    /// </remarks>
    bool connect(const std::string& poleName, Object& other, const std::string& otherPoleName);

    /// <summary>
    /// Отключает указанный полюс, если к нему что-либо подключено.
    /// </summary>
    /// <param name="poleName">Название полюса, от которого производится отключение.</param>
    /// <returns><c>true</c> если что-либо было отключено, <c>false</c> в противном случае.</returns>
    /// <remarks>
    /// Вызов этого метода для полюса, если к нему ничего не подключено, не является ошибкой.
    /// </remarks>
    bool disconnect(const std::string& poleName);
};

/// <summary>
/// Простой выключатель с двумя полюсами.
/// </summary>
class Switch : public Object {
public:
    Pole a1, a2;

    Switch(const std::string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};

// TODO: класс светильника с двумя полюсами

// TODO: класс генератора с тремя полюсами (фаза, нейтраль, земпя).
class Lamp : public Object {
public:
    Pole a1, a2;

    Lamp(const std::string& name = "");

    size_t getPoleCount() const override { return 2; }

    const Pole* getPole(const std::string& name) const override;

protected:
    const Pole* getPole(size_t idx) const override;
};

class Generator : public Object {
public:
    Pole a1, a2, a3;

    Generator(const std::string& name = "");

    size_t getPoleCount() const override { return 3; }

    const Pole* getPole(const std::string& name) const override;

protected:
    const Pole* getPole(size_t idx) const override;
};