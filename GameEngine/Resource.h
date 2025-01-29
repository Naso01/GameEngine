#ifndef RESOURCE_H
#define RESOURCE_H

#include "Serializable.h"
#include "AssetController.h"

class Resource : public Serializable
{
public:
	// Constructors/Destructors
	Resource();
	virtual ~Resource();

	//Methods
	virtual void Serialize(ostream& _stream);
	virtual void Deserialize(istream& _stream);
	void AssignNonDefaultValues();
	void ToString();
	

	//Members
	static ObjectPool<Resource>* Pool;


protected:
	void SerializePointer(ostream& _stream, Resource* _pointer);
	void DeserializePointer(istream& _stream, Resource*& _pointer);
	void SerializeAsset(ostream& _stream, Asset* _asset);
	void DeserializeAsset(istream& _stream, Asset*& _asset);

private:
	int m_val1;
	double m_val2;
	char m_val3;
	Resource* m_subResource;
	Asset* m_asset;
};

#endif // RESOURCE_H