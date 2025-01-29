#include "Asset.h"
#include "AssetController.h"

int main()
{
    AssetController::Instance().Initialize(1000000); //Allocate 10MB
    Asset* asset = AssetController::Instance().GetAsset("Emoji.jpg");
    cout << "Bytes used by image.bmp: "<< asset->GetDataSize() << endl;


}