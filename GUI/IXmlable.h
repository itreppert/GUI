#pragma once
namespace GUI {
	public interface class IXmlable
	{
		void addToVerzeichnisXml(System::Xml::XmlDocument^ targetXmlDocument, System::String^ type);
		bool deleteFromVerzeichnisXml(System::Xml::XmlDocument^ sourceXmlDocument);
		void getFromVerzeichnisXml(System::Xml::XmlDocument^ sourceXmlDocument);
	};
}
