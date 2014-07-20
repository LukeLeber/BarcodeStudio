/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 */

constexpr bool operator==(const DefaultModule& vm0, const DefaultModule& vm1) noexcept
{
    return vm0.weight == vm1.weight && vm0.on == vm1.on;
}

constexpr bool operator!=(const DefaultModule& vm0, const DefaultModule& vm1) noexcept
{
    return vm0.weight != vm1.weight || vm0.on != vm1.on;
}

constexpr DefaultModule::DefaultModule(std::size_t weight, bool on) noexcept : 
    weight(weight), on(on)
{
    
}

constexpr std::size_t DefaultModule::getWeight() const noexcept
{
    return this->weight;
}

constexpr DefaultModule::operator bool() const noexcept
{
    return this->on;
}
