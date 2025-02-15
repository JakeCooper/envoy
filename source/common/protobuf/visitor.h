#pragma once

#include "envoy/common/pure.h"

#include "source/common/protobuf/protobuf.h"

namespace Envoy {
namespace ProtobufMessage {

class ConstProtoVisitor {
public:
  virtual ~ConstProtoVisitor() = default;

  // Invoked when a field is visited, with the message, and field descriptor.
  virtual void onField(const Protobuf::Message&, const Protobuf::FieldDescriptor&) PURE;

  // Invoked when a message is visited, with the message.
  // @param was_any_or_top_level supplies whether the message was either the top level message or an
  //                             Any before being unpacked for further recursion. The latter can
  //                             only be achieved by using recurse_into_any.
  virtual void onMessage(const Protobuf::Message&, bool was_any_or_top_level) PURE;
};

void traverseMessage(ConstProtoVisitor& visitor, const Protobuf::Message& message,
                     bool recurse_into_any);

} // namespace ProtobufMessage
} // namespace Envoy
