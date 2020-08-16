/*
	By Jenocn
	https://jenocn.github.io/
*/

#include "MessageCenter.h"
#include "MessageDispatcher.h"

using namespace GCL::Pattern;

MessageDispatcher* MessageCenter::_messageDispatcher = new MessageDispatcher();

void MessageCenter::Send(MessagePtr message) {
	_messageDispatcher->Send(message);
}

void MessageCenter::Push(MessagePtr message) {
	_messageDispatcher->Push(message);
}

void MessageCenter::OnDispatch() {
	_messageDispatcher->OnDispatch();
}

void MessageCenter::Clear() {
	_messageDispatcher->Clear();
}

MessageDispatcher* MessageCenter::GetCenterDispatcher() {
	return _messageDispatcher;
}

MessageDispatcher* MessageCenter::GetCustomDispatcher(const std::string& name) {
	auto ite = _customDispatcherMap.find(name);
	if (ite != _customDispatcherMap.end()) {
		return ite->second.get();
	}
	auto ret = std::shared_ptr<MessageDispatcher>(new MessageDispatcher());
	_customDispatcherMap.emplace(name, ret);
	return ret.get();
}
