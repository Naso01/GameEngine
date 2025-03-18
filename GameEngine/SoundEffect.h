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

	Asset* GetData() { return m_effect; }

	//Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;

	void Load(string _guid);

	//Members
	static ObjectPool<SoundEffect>* Pool;

private:
	Asset* m_effect;
};

#endif // SOUND_EFFECT_H