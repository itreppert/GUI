#pragma once
namespace GUI {

	public interface class IDatabaseable {
		bool load();
		bool update();
		int deleteMe();
		int insert();
	};









}