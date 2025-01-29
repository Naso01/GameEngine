#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H

#include "Resource.h"
class Asset;

class SoundEffect : public Resource
{
public:
	//Constuctors/Destructors
	SoundEffect();
	virtual ~SoundEffect();

	//Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;

	//Members
	static ObjectPool<SoundEffect>* Pool;

private:
	Asset* m_effect;
};

#endif // SOUND_EFFECT_H